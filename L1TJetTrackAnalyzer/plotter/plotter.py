import os, subprocess 
from optparse import OptionParser
import multiprocessing as mp
from ROOT import *
import time;
import sys

sys.path.insert(1, 'PlottingCore/')
from SingleEfficiency import SingleEfficiency
from SinglePlot import SinglePlot
from PerSampleEfficiency import PerSampleEfficiency
from PerSamplePlot import PerSamplePlot

def f(x):
  args = x.split(";")
  print x
  qt= "\",\""
  os.system(  "root -l -b -q 'PlottingCore/"+args[0]+"(\""+args[1]+qt+args[2]+qt+args[3]+qt+args[4]+qt+args[5]+"\")'"   )
  print "core",(args[2].split("_"))[1],"done"



if __name__ == "__main__":
    # availiable plotting options
    parser = OptionParser()

    parser.add_option("-p","--plotsTxtFile", dest="plotfile",   default="plots.txt", type="string", help="txt with selected plots and cuts")
    parser.add_option("-s","--script", dest="script", default="Plots", type="choice",choices= ['Efficiency','Plots'], help="plotter type choices: EfficiencyPlots or SimplePlots")
    parser.add_option("-i","--inputData" ,dest="inputData",  default="mca.txt", type="string", help="txt with root files to run on. By default running on mca.txt")
    parser.add_option("-o","--outputDir",dest="outputDir",  default="Plots_Date", type="string", help="folder name to save plots. Default=Plots_Date")
    parser.add_option("-f","--forceRewrite",dest="rewriteOutDir",  default=False,action='store_true', help="if the outputDir exists, this rewrites it (previous deleted)")
    parser.add_option("-n","--ncore",dest="ncore",type="int",  default=-1, help="number of cores to use. -1 uses all")
    parser.add_option("--tree",dest="tree",  default="L1TrackNtuple/Events", type="string", help="tree name. Default Events")
   
    (options, args) = parser.parse_args()

   

    if  os.path.exists(options.outputDir) and options.rewriteOutDir:
        os.system("rm -r "+options.outputDir)

     #  create output folder to save plots
    if options.outputDir=="Plots_Date":
      localtime = time.asctime( time.localtime(time.time()) )
      options.outputDir = "Plots_{0}".format(localtime.replace(" ","_"))
      options.outputDir = options.outputDir.replace(":","_")
      os.system(  "mkdir -p "+options.outputDir )
      print "plots will be saved at "+options.outputDir
      
    else:
      print "plots will be saved at "+options.outputDir
      if not os.path.exists(options.outputDir):    
         os.makedirs(options.outputDir)
      else:
         num1=0
         while os.path.exists(options.outputDir+"_{0}".format(str(num1)) ):
           num1+=1
         options.outputDir=options.outputDir+"_{0}".format(str(num1))
         print "directory exist. will save at "+options.outputDir
         

    os.system("cp "+options.plotfile+" "+options.outputDir)
    os.system("cp "+options.inputData+" "+options.outputDir)

    script="plotEfficiency.C"
    if options.script=="Plots": script="plotSimple.C"
      
    #create tmp folder inside the output directory - will be erased at the end
    workdir =  options.outputDir+"/temp"
    os.makedirs(workdir)
    
    nlines=0
    with open(options.inputData,"r") as inf:
      lines=inf.readlines()
      nlines=len(lines)


    ncores=mp.cpu_count()
    if nlines<mp.cpu_count(): ncores=nlines
    if options.ncore!=-1: ncores=options.ncore
    files = [open(workdir+'/mca_%d.txt' % i, 'w') for i in range(ncores)]

    print "job distributed in",ncores,"cores"

    legs=[]
    plot_type=1
    for i,line in enumerate(lines):
      if line.startswith("#"): continue;
      if not line.strip(): continue;
      if line=="\n": continue;
      itxt = i % ncores 
      if ":" in line:
        words= line.split(":")
        legs.append(words[0])
        files[itxt].write(words[1])
        plot_type=2
      else:
         files[itxt].write(line) 

      
    for fi in files:
      fi.close() 

    chunk_names=[]
    jobs=[]
    for i in range(0,ncores):
       temp=script+";"+workdir+";"+str('histo_%d' % i)+";"+str('mca_%d.txt' % i)+";"+options.plotfile+";"+options.tree
       chunk_names.append(str('/histo_%d.root  ' % i))
       jobs.append(temp)


    p = mp.Pool(ncores)
    p.map(f,jobs)


    print "stage 2... "
    gROOT.SetBatch(True)
    
    if options.script=="Plots":
      if plot_type==1:
        SinglePlot(chunk_names,workdir,options.outputDir)   
      else:
        PerSamplePlot(legs,chunk_names,workdir,options.outputDir)
    elif options.script=="Efficiency": 
      if plot_type==1:
        SingleEfficiency(chunk_names,workdir,options.outputDir)
      else:
        PerSampleEfficiency(legs,chunk_names,workdir,options.outputDir)
    else:
      print "uknown plot option. terminate.."
      exit()
    
    os.system( "mv "+workdir+"/hsum.root   "+options.outputDir+"/histos.root" )
    os.system( "rm -r "+workdir )
    print "finished !"
  
