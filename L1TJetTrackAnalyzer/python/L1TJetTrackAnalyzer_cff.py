import FWCore.ParameterSet.Config as cms

L1TrackNtuple = cms.EDAnalyzer('L1TJetTrackAnalyzer',
                                       TwoLayerJetsInputTag=cms.InputTag("L1TrackJets", "L1TrackJets", "L1TrackJets"),
                                       FastJetsInputTag = cms.InputTag("L1TrackFastJets","L1TrackFastJets"),
                                       TrackingJetsInputTag=cms.InputTag("L1FastTrackingJets","L1FastTrackingJets"),
                                       GenJetsInputTag = cms.InputTag("ak4GenJets", ""),
                                       FastJetsExtInputTag=cms.InputTag("L1TrackFastJetsExtended","L1TrackFastJetsExtended"),
                                       TwoLayerJetsExtInputTag= cms.InputTag("L1TrackJetsExtended", "L1TrackJetsExtended"),
                                       TrackingJetsExtInputTag=cms.InputTag("L1FastTrackingJetsExtended","L1FastTrackingJetsExtended"),
                                       TracksInputTag = cms.InputTag("TTTracksFromTrackletEmulation", "Level1TTTracks"),
                                       TracksExtInputTag = cms.InputTag("TTTracksFromExtendedTrackletEmulation", "Level1TTTracks"),
                                       GenTrackInfoInputTag = cms.InputTag("TTTrackAssociatorFromPixelDigis", "Level1TTTracks"),
                                       GenExtTrackInfoInputTag = cms.InputTag("TTTrackAssociatorFromPixelDigisExtended", "Level1TTTracks"),
                                       EtMissInputTag = cms.InputTag("L1TrackerEtMiss","L1TrackerEtMiss","L1TrackJets"),
                                       HTMissInputTag = cms.InputTag("L1TrackerHTMiss","L1TrackerHTMiss","L1TrackJets"),
                                       PVInputTag =cms.InputTag("L1TkPrimaryVertex"),
                                       GenPartInputTag =cms.InputTag("genParticles"),
                                       L1GenJetMatchDR = cms.double(0.3),
                                       AddExtendedL1Jets= cms.bool(True),
                                       AddExtendedL1Tracks = cms.bool(True)
)

