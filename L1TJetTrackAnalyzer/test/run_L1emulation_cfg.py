############################################################
# define basic process
############################################################

import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils
from FWCore.ParameterSet.VarParsing import VarParsing
import os

options = VarParsing('python')

options.register('globalTag', 'auto:phase2_realistic',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Set global tag"
)

options.register('wantFullReco', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Run this on real data"
)

options.register('reportEvery', 100,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    "report every N events"
)

options.register('addDisplaced', False,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "displaced jets"
)

options.register('addPrompt', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "adds prompt"
)


options.setDefault('maxEvents', 10)
options.setDefault('tag', 'test')
options.parseArguments()

############################################################
# edit options here
############################################################
L1TRK_INST ="L1TrackJets" ### if not in input DIGRAW then we make them in the above step
process = cms.Process(L1TRK_INST)


if not options.addDisplaced:
  L1TRKALGO = 'HYBRID'  #baseline, 4par fit
else:
  L1TRKALGO = 'HYBRID_PROMPTANDDISP'




DISPLACED = ''

############################################################
# import standard configurations
############################################################
process.load('FWCore.MessageService.MessageLogger_cfi')

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.Geometry.GeometryExtended2026D49Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2026D49_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, options.globalTag, '')

############################################################
# input and output
############################################################
process.MessageLogger.cerr.FwkReport.reportEvery = options.reportEvery
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(options.maxEvents))
#process.options = cms.untracked.PSet(
#SkipEvent = cms.untracked.vstring('ProductNotFound')
#)
readFiles = cms.untracked.vstring(
#    "/store/relval/CMSSW_11_1_0_pre2/RelValTTbar_14TeV/GEN-SIM-DIGI-RAW/PU25ns_110X_mcRun4_realistic_v2_2026D49PU200-v1/20000/F7BF4AED-51F1-9D47-B86D-6C3DDA134AB9.root"
#  "/store/mc/Phase2HLTTDRWinter20DIGI/TT_TuneCP5_14TeV-powheg-pythia8/GEN-SIM-DIGI-RAW/NoPU_110X_mcRun4_realistic_v3-v2/40000/6AC1E53C-45CE-E74F-BEEA-649119E1DCB8.root"
 "/store/mc/Phase2HLTTDRWinter20DIGI/HiddenGluGluH_mH-250_Phi-60_ctau-10_TuneCP5_14TeV-pythia8/GEN-SIM-DIGI-RAW/NoPU_110X_mcRun4_realistic_v3-v2/240000/19EF5920-9BC1-104E-A612-42EC6406EF5B.root"
)
secFiles = cms.untracked.vstring()

process.source = cms.Source ("PoolSource",
                            fileNames = readFiles,
                            secondaryFileNames = secFiles,
#                            duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
 #                          eventsToProcess=cms.untracked.VEventRange('1:7:6303-1:7:6313')
                            )

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
)

process.TFileService = cms.Service("TFileService", fileName = cms.string('L1Jets_'+options.tag+'.root'), closeFileFast = cms.untracked.bool(True))



process.load("L1Trigger.TrackFindingTracklet.L1HybridEmulationTracks_cff")
process.load("L1Trigger.L1TTrackMatch.L1TrackJetProducer_cfi")
process.load("L1Trigger.L1TTrackMatch.L1TrackFastJetProducer_cfi")
process.load("L1Trigger.L1TTrackMatch.L1FastTrackingJetProducer_cfi")
process.load("L1Trigger.L1TTrackMatch.L1TrackerEtMissProducer_cfi")
process.load("L1Trigger.L1TTrackMatch.L1TkHTMissProducer_cfi")


# HYBRID: prompt tracking
if (L1TRKALGO == 'HYBRID'):
    process.TTTracksEmulation = cms.Path(process.L1HybridTracks)
    process.TTTracksEmulationWithTruth = cms.Path(process.L1HybridTracksWithAssociators)
    process.pL1TrackJets = cms.Path(process.L1TrackJets)
    process.pL1TrackFastJets=cms.Path(process.L1TrackFastJets)
    process.pL1FastTrackingJets=cms.Path(process.L1FastTrackingJets)
    process.pTkMET = cms.Path(process.L1TrackerEtMiss)
    process.pTkMHT = cms.Path(process.L1TrackerHTMiss)
    DISPLACED = 'Prompt'

# HYBRID: extended tracking
elif (L1TRKALGO == 'HYBRID_DISPLACED'):
    process.TTTracksEmulation = cms.Path(process.L1ExtendedHybridTracks)
    process.TTTracksEmulationWithTruth = cms.Path(process.L1ExtendedHybridTracksWithAssociators)
    process.pL1TrackJets = cms.Path(process.L1TrackJetsExtended)
    process.pL1TrackFastJets = cms.Path(process.L1TrackFastJetsExtended)
    process.pL1FastTrackingJets=cms.Path(process.L1FastTrackingJetsExtended)
    process.pTkMET = cms.Path(process.L1TrackerEtMissExtended)
    process.pTkMHT = cms.Path(process.L1TrackerHTMissExtended)
    DISPLACED = 'Displaced'#

# HYBRID: extended tracking
elif (L1TRKALGO == 'HYBRID_PROMPTANDDISP'):
#    process.TTTracksEmulation = cms.Path(process.L1PromptExtendedHybridTracks)
    process.TTTracksEmulation = cms.Path(process.L1HybridTracks*process.L1ExtendedHybridTracks)
#    process.TTTracksEmulationWithTruth = cms.Path(process.L1PromptExtendedHybridTracksWithAssociators)
    process.TTTracksEmulationWithTruth = cms.Path(process.L1HybridTracksWithAssociators*process.L1ExtendedHybridTracksWithAssociators)
    process.pL1TrackJets = cms.Path(process.L1TrackJets*process.L1TrackJetsExtended)
    process.pL1TrackFastJets = cms.Path(process.L1TrackFastJets*process.L1TrackFastJetsExtended)
    process.pL1FastTrackingJets=cms.Path(process.L1FastTrackingJets*process.L1FastTrackingJetsExtended)
    process.pTkMET = cms.Path(process.L1TrackerEtMiss*process.L1TrackerEtMissExtended)
    process.pTkMHT = cms.Path(process.L1TrackerHTMiss*process.L1TrackerHTMissExtended)
    DISPLACED = 'Both'


############################################################
# Primary vertex
############################################################
process.load("L1Trigger.L1TTrackMatch.L1TkPrimaryVertexProducer_cfi")
process.L1TkPrimaryVertex.nVtx = cms.int32 (5)
if DISPLACED ==	'Displaced':
   process.L1TkPrimaryVertex.L1TrackInputTag = cms.InputTag("TTTracksFromExtendedTrackletEmulation", "Level1TTTracks")
process.pPV = cms.Path(process.L1TkPrimaryVertex)


process.L1TrackNtuple = cms.EDAnalyzer('L1TJetTrackAnalyzer',
                                       TwoLayerJetsInputTag=cms.InputTag("L1TrackJets", "L1TrackJets", "L1TrackJets"),
                                       FastJetsInputTag = cms.InputTag("L1TrackFastJets","L1TrackFastJets"),
                                       GenJetsInputTag = cms.InputTag("ak4GenJets", ""),
                                       FastJetsExtInputTag=cms.InputTag("L1TrackFastJetsExtended","L1TrackFastJetsExtended"),
                                       TwoLayerJetsExtInputTag= cms.InputTag("L1TrackJetsExtended", "L1TrackJetsExtended"),
                                       TracksInputTag = cms.InputTag("TTTracksFromTrackletEmulation", "Level1TTTracks"),
                                       TracksExtInputTag = cms.InputTag("TTTracksFromExtendedTrackletEmulation", "Level1TTTracks"),
                                       GenTrackInfoInputTag = cms.InputTag("TTTrackAssociatorFromPixelDigis", "Level1TTTracks"),
                                       GenExtTrackInfoInputTag = cms.InputTag("TTTrackAssociatorFromPixelDigisExtended", "Level1TTTracks"),
                                       EtMissInputTag = cms.InputTag("L1TrackerEtMiss","L1TrackerEtMiss","L1TrackJets"),
                                       HTMissInputTag = cms.InputTag("L1TrackerHTMiss","L1TrackerHTMiss","L1TrackJets"),
                                       PVInputTag =cms.InputTag("L1TkPrimaryVertex"),
                                       L1GenJetMatchDR = cms.double(0.3),
                                       AddExtendedL1Jets= cms.bool(options.addDisplaced),
                                       AddExtendedL1Tracks = cms.bool(options.addDisplaced)
)

process.ntuple = cms.Path(process.L1TrackNtuple)

process.out = cms.OutputModule( "PoolOutputModule",
                                fastCloning = cms.untracked.bool( False ),
                                fileName = cms.untracked.string("test.root" )
		               )
process.pOut = cms.EndPath(process.out)

process.output = cms.OutputModule(
        "PoolOutputModule",
        outputCommands = cms.untracked.vstring("keep *",
    ),
        fileName = cms.untracked.string('l1t_EDM_'+options.tag+'.root')
)
process.poutput= cms.EndPath(process.output)


if options.wantFullReco:
   process.schedule = cms.Schedule(process.TTTracksEmulationWithTruth, process.pPV, process.pL1TrackJets, process.pL1TrackFastJets,process.pL1FastTrackingJets, process.pTkMET, process.pTkMHT, process.poutput)
else: 
   process.schedule = cms.Schedule(process.TTTracksEmulationWithTruth, process.pPV, process.pL1TrackJets, process.pL1TrackFastJets,process.pL1FastTrackingJets, process.pTkMET, process.pTkMHT, process.ntuple)
