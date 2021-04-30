#Code for L1 Track and Track Objects analysis

* Main Objective: Have a common reference code for all projects regarding L1T Tracks
* Status of the code: Important branches are availiable, passed extensive tests
* Code version: 3.1
* Presentations in the GTT meeting:
  - Ntuplizer: https://indico.cern.ch/event/1009246/contributions/4235306/attachments/2193499/3707865/L1TrkJetFW.pdf
  - Plotting: https://indico.cern.ch/event/1012970/contributions/4282920/attachments/2212159/3744126/L1TrkJetFW2.pdf 
<hr>
Updates:
* Added more variables
* Added tracking jets
* Small bug fixes
* Cosmetics for plots
<hr>

#Instructions for installation
 Can be added on top of any CMSSW enviroment with "git clone https://github.com/gkaratha/L1TrackJetAnalysis"
 * Note: Please use any **Phase 2** environment

#Creating Ntuples
 This step takes as input CMSSW RAW files or GEN-SIM-RAW and produces the final ntuples. The configuration of the ntuplizer is in the "L1TrackJetAnalysis/python" directory. There one can change the input tags, add/skip extended tracking etc
 
 
 * Running Locally:
    - In the "L1TrackJetAnalysis/test" directory there are two files:
	- run_L1emulation_cfg.py: Runs full emulation of L1 .&. the ntuplizer
        - run_analyzer.py: Runs only the ntuplizer (here the input must already include the L1T info)
    - Both can be ran with cmsRun
    - Flags can be used to perform the basic changes (eg number of evts, report frequency, globalTag etc). To change the flag just add Flag=Value (eg cmsRun run_L1emulation_cfg.py globalTag=...) 

 * Running on CRAB:
    - While in the "L1TrackJetAnalysis/production" directory
    - Add your sample in the yml file (look at samples.yml as example)
    - Run with python submit.py -y <ymlSampleFile> -f <sampleName> --totalUnits <FilesToProcess>

#Plotting Toll
 Takes as input any ROOT file with a TTree and produces the final plots. It takes minimum two files for input the samples file and the plot file, both of which are simple txt files. The command to run it is: 
        _python plotter.py -i <samples> -p <plots> -o <output>_

* Avaliliable Flags:
    - -f if the output folder exists already, this will overwrite it. Otherwise the code will just add a Number at the end, showing the version
    - -s define if we want efficiency plots or just plain histograms
    - -n number of cores 
    - --tree the name of the tree to process

* Samples definition:
Add the paths with the individual files or the folders one-by-one. The * wildcard is supported. By adding a title to a and ":" before a sample will cause the samples to be treated as different samples. Otherwise they will be treated as one and will be summed. As example of the two cases please see mca_test and mca_test_t2

* Plots definition:
Every new histogram is booked in different line and follow a formatted logic. The minimal entries for a simple histogram are:
  *Name:plotted variable: cuts / None for no cuts : X-axis title : bins : min X axis : max Xaxis : canvas name*
For efficiency plots the above must modified like:
 *Name:plotted variable: denominator cuts : Extra numerator cuts : X-axis title : bins : min X axis : max Xaxis : canvas name*

Histograms in the same canvas will be automatically superimposed. After the canvas name one can add many flags in order to change the cosmetics. Few examples are:
  - LineColor/LineWidth: Sets line color/width
  - XLabelSize/YLabelSize: Sets title size
  - YTitle: name of y-axis
  - Cumulative/InverseCumulative: produces integrated plots over the x-axis variable
  - Rate: Cimputes rates in Hz
  - LegPos: Sets legend position; options: BL (Bottom Left), TR (Top Right), BR, TL
  - LegName: Sets histo name in legend
  - Fit: Fits Error function, Plo2 or gaussian in a user-defined range (binned likelihood)
