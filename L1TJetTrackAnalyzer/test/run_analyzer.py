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

process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10))

readFiles=["file:/afs/cern.ch/work/g/gkaratha/private/L1TrackTrigger/CMSSW_11_1_6/src/L1Trigger/TrackFindingTracklet/test/l1t_EDM_Prompt.root"]

process.source = cms.Source ("PoolSource",
                            fileNames = cms.untracked.vstring(readFiles),
                            secondaryFileNames = cms.untracked.vstring(),
                            duplicateCheckMode = cms.untracked.string('noDuplicateCheck'),
                            )

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True),
)
process.L1TJetTrackNtuple = cms.EDAnalyzer('L1TJetTrackAnalyzer',
                                            TrackJetsInputTag=cms.InputTag("L1TrackJets", "L1TrackJets"),
                                            FastJetsInputTag = cms.InputTag("L1TrackFastJets","L1TrackFastJets"),
                                            GenJetsInputTag = cms.InputTag("ak4GenJets", ""),
                                            TracksInputTag = cms.InputTag("TTTracksFromTrackletEmulation", "Level1TTTracks"),
                                            GenTrackInfoInputTag = cms.InputTag("TTTrackAssociatorFromPixelDigis", "Level1TTTracks")
)
process.TFileService = cms.Service("TFileService", fileName = cms.string('L1Jets_test.root'), closeFileFast = cms.untracked.bool(True))

process.ntuple = cms.Path(process.L1TJetTrackNtuple)
process.out = cms.OutputModule( "PoolOutputModule",
                                fastCloning = cms.untracked.bool( False ),
                                fileName = cms.untracked.string("test.root" )
                               )
process.pOut = cms.EndPath(process.out)

process.schedule = cms.Schedule(process.ntuple)



