# Code for L1 Track and Track Objects analysis
>
* Main Objective: Have a common reference code for all projects involing L1T Tracks (eg TrackJets, TrackMET etc)
* Status of the code: Important branches are available, passed extensive tests
* Code version: 3.1
* Presentations in the GTT meeting (~tutorials):
  - Ntuplizer: https://indico.cern.ch/event/1009246/contributions/4235306/attachments/2193499/3707865/L1TrkJetFW.pdf
  - Plotting: https://indico.cern.ch/event/1012970/contributions/4282920/attachments/2212159/3744126/L1TrkJetFW2.pdf 
<hr>

**Updates :
 * More variables
 * Added tracking jets
 * Small bug fixes
 * Cosmetics for plots**

<hr> 

# Instructions for installation
>
 Can be added on top of any CMSSW environment with "git clone https://github.com/gkaratha/L1TrackJetAnalysis"
 * Note: Please use any **Phase 2** environment

# Creating Ntuples
>
 This step takes as input CMSSW RAW files or GEN-SIM-RAW and produces the final ntuples. The configuration of the ntuplizer is in the "L1TrackJetAnalysis/python" directory. In that directory, one can change the input tags, add/skip extended tracking etc
 
 
 * Running Locally:
    - In the "L1TrackJetAnalysis/test" directory there are two files:
	- run_L1emulation_cfg.py: Runs full emulation of L1 .&. the ntuplizer
        - run_analyzer.py: Runs only the ntuplizer (the input must already include the L1T info)
    - Both can be ran with cmsRun
    - Flags can be used to perform the basic changes on-the-fly (eg number of evts, report frequency, globalTag etc). Example: To change global tag, one needs to simply add globalTag=Value (eg cmsRun run_L1emulation_cfg.py globalTag=...) 

 * Running on CRAB:
    - While in the "L1TrackJetAnalysis/production" directory
    - Add your sample in the yml file (look at samples.yml as example)
    - Run with python submit.py -y < ymlSampleFile > -f < sampleName > --totalUnits < Number of FilesToProcess >

# Plotting Tool
 Takes as input any ROOT file with a TTree structure and produces the final plots. It takes at minimum two files as inputs, a file with the directory of the samples and a file with the histograms we want to plot.. Both of files are in simple txt format. The command to run it is: 
  >      python plotter.py -i <samples> -p <plots> -o <output>

* Available Flags:
    - -f if the output folder exists already, this will overwrite it. Otherwise the code will just add a “ _Number “ at the end, showing the version of the directory
    - -s define if we want efficiency plots or just plain histograms
    - -n number of cores 
    - --tree the name of the tree to process

* Samples definition:
Includes the paths with the individual files or the folders to process. Each path should be an independent line. The use of " * " wildcard is supported. By adding a title and ":" before any path will cause the input files to be treated as different sample. Otherwise they will be treated as one and will be summed. As example of the two cases please see mca_test and mca_test_t2 . This file can be created automatically also with the createMca.py 

* Plots definition:
Every new histogram is booked in different line and follow a formatted logic. The minimal entries for a simple histogram are:
  *Name:plotted variable: cuts / None for no cuts : X-axis title : bins : min X axis : max Xaxis : canvas name*
For efficiency plots the above must modified to take into account the different cuts in numerator/denominator, like:
 *Name:plotted variable: denominator cuts : Extra numerator cuts : X-axis title : bins : min X axis : max Xaxis : canvas name*

   Histograms in the same canvas will be automatically superimposed. After the canvas name, somebody can add as many flags as needed in order to tune the cosmetics. Few examples are:
  - LineColor/LineWidth: Sets line color/width
  - XLabelSize/YLabelSize: Sets title size
  - YTitle: name of y-axis
  - Cumulative/InverseCumulative: produces integrated plots over the x-axis variable
  - Rate: Computes rates in Hz
  - LegPos: Sets legend position; options are: BL (Bottom Left), TR (Top Right), BR, TL
  - LegName: Sets histo name in legend
  - Fit: Fits Error function, Pol2 or Gaussian in a user-defined range (binned likelihood)