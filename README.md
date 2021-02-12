Code for L1 Track and Track Objects analysis:

- Main Objective: Have a common reference code for all projects regarding L1 Tracks
- Status of the code: Important branches are availiable, passed extensive tests
- Code version: 1.0

Instructions:
 Can be added in any CMSSW enviroment with "git clone https://github.com/gkaratha/L1TrackJetAnalysis"
 -> Note: Please use any *Phase 2* environment

 - Running locally:
    - While in the "L1TrackJetAnalysis/test" directory
    - Run run_L1emulation_cfg.py with cmsRun (emulates L1 tracks and Jets from RAW)
    - Flags can be used to perform the basic changes (eg number of evts, report frequency etc)

 - Running in CRAB:
    - While in the "L1TrackJetAnalysis/production" directory
    - Add your sample in a yml file (look at samples.yml as example)
    - Run with python submit.py -y yml_sample_file -f sample_name
