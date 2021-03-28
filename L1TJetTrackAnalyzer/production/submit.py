from CRABClient.UserUtilities import config, ClientException
#from input_crab_data import dataset_files
import yaml
import datetime
from fnmatch import fnmatch
from argparse import ArgumentParser

production_tag = datetime.date.today().strftime('%Y%b%d')

config = config()
config.section_('General')
config.General.transferOutputs = True
config.General.transferLogs = True
config.General.workArea = 'L1Tracker_%s' % production_tag

config.section_('Data')
config.Data.publication = False
config.Data.outLFNDirBase = '/store/group/cmst3/user/gkaratha/%s' % (config.General.workArea)
config.Data.inputDBS = 'global'
config.Data.totalUnits= 1000

config.section_('JobType')
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../test/run_L1emulation_cfg.py'
config.JobType.maxMemoryMB = 4000
config.JobType.allowUndistributedCMSSW = True

config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_CH_CERN'

if __name__ == '__main__':

  from CRABAPI.RawCommand import crabCommand
  from CRABClient.ClientExceptions import ClientException
  from httplib import HTTPException
  from multiprocessing import Process

  def submit(config):
      try:
          crabCommand('submit', config = config)
      except HTTPException as hte:
          print "Failed submitting task: %s" % (hte.headers)
      except ClientException as cle:
          print "Failed submitting task: %s" % (cle)


  parser = ArgumentParser()
  parser.add_argument('-y', '--yaml', default = 'samples.yml', help = 'File with dataset descriptions')
  parser.add_argument('-f', '--filter', default='*', help = 'filter samples, POSIX regular expressions allowed')
  parser.add_argument('-d', '--addDisplaced', default='False', help = 'filter samples, POSIX regular expressions allowed')
  parser.add_argument('-p', '--addPrompt', default='False', help = 'filter samples, POSIX regular expressions allowed')
  parser.add_argument('--wantFullReco', default='False', help = 'filter samples, POSIX regular expressions allowed')
  args = parser.parse_args()

  with open(args.yaml) as f:
    doc = yaml.load(f) # Parse YAML file
    common = doc['common'] if 'common' in doc else {'data' : {}, 'mc' : {}}
    
    # loop over samples
    for sample, info in doc['samples'].iteritems():
      
      # filter names according to what we need
      if not fnmatch(sample, args.filter): continue
      print 'submitting', sample


      config.Data.inputDataset = info['dataset']

      config.General.requestName = sample
      config.Data.splitting = 'FileBased'

      config.Data.unitsPerJob = info['split']
      
        
      config.JobType.pyCfgParams = [
            'reportEvery=1000',
            'tag=%s' % production_tag,
            'addDisplaced=%s' % args.addDisplaced,
            'addPrompt=%s' % args.addPrompt,
            'wantFullReco=%s' % args.wantFullReco
        ]
        
      config.JobType.outputFiles = ['_'.join(['L1Jets', production_tag])+'.root']
        
      print config
      submit(config)
