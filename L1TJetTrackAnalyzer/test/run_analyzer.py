import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

process = cms.Process("L1TTrackJets")


process.load('FWCore.MessageService.MessageLogger_cfi')

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.Geometry.GeometryExtended2026D49Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2026D49_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')

process.MessageLogger.cerr.FwkReport.reportEvery = 1000
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

readFiles=[
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-0_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau0/210225_140002/0000/l1t_EDM_2021Feb25_1.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-0_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau0/210225_140002/0000/l1t_EDM_2021Feb25_2.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-0_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau0/210225_140002/0000/l1t_EDM_2021Feb25_3.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-0_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau0/210225_140002/0000/l1t_EDM_2021Feb25_4.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-10_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau10/210225_135944/0000/l1t_EDM_2021Feb25_1.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-10_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau10/210225_135944/0000/l1t_EDM_2021Feb25_2.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-10_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau10/210225_135944/0000/l1t_EDM_2021Feb25_3.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-10_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau10/210225_135944/0000/l1t_EDM_2021Feb25_4.root"
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-50_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau50/210225_135906/0000/l1t_EDM_2021Feb25_1.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-50_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau50/210225_135906/0000/l1t_EDM_2021Feb25_3.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-50_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau50/210225_135906/0000/l1t_EDM_2021Feb25_4.root",
#"/store/cmst3/user/gkaratha/L1Tracker_2021Feb25/HiddenGluGluH_mH-250_Phi-60_ctau-50_TuneCP5_14TeV-pythia8/crab_GluGluH_ctau50/210225_135906/0000/l1t_EDM_2021Feb25_5.root"
]

import os
mypath="/eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Feb28/MinBias_TuneCP5_14TeV-pythia8/crab_MinimumBias/210228_224640/0000"
for (dirpath, dirnames, filenames) in os.walk(mypath):
  for filenm in filenames:
    if "l1t_EDM_2021Feb28" in filenm:
        readFiles.append("/store/cmst3/user/gkaratha/L1Tracker_2021Feb28/MinBias_TuneCP5_14TeV-pythia8/crab_MinimumBias/210228_224640/0000/"+filenm)

process.source = cms.Source ("PoolSource",
                            fileNames = cms.untracked.vstring(readFiles),
                            secondaryFileNames = cms.untracked.vstring(),
                            duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
                            )

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
)

process.load('L1Trigger.L1TJetTrackAnalyzer.L1TJetTrackAnalyzer_cff')
process.ntuple= cms.Path(process.L1TrackNtuple)

process.TFileService = cms.Service("TFileService", fileName = cms.string('L1Jets_MinBias.root'), closeFileFast = cms.untracked.bool(True))


process.out = cms.OutputModule( "PoolOutputModule",
                                fastCloning = cms.untracked.bool( False ),
                                fileName = cms.untracked.string("test.root" )
                               )
process.pOut = cms.EndPath(process.out)

process.schedule = cms.Schedule(process.ntuple)



