#ifndef L1TRACK_H
#define L1TRACK_H
#include "NtupleContent.h"

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/L1TrackTrigger/interface/TTTypes.h"
#include "DataFormats/L1TrackTrigger/interface/TTTrack.h"
#include "SimTracker/TrackTriggerAssociation/interface/TTTrackAssociationMap.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticle.h"

#include <math.h>

class L1Track{
  public:
    L1Track(){};
    L1Track(const edm::EDGetTokenT<std::vector< TTTrack<Ref_Phase2TrackerDigi_> >> &L1TrkToken_, const edm::Event &iEvent);
    ~L1Track();

    void ReadData(const edm::EDGetTokenT<std::vector< TTTrack<Ref_Phase2TrackerDigi_> >> &L1TrkToken_, const edm::Event &iEvent);
    void FillBranches(std::string Col, NtupleContent &nt);
    void FillMCBranches(const edm::EDGetTokenT<TTTrackAssociationMap<Ref_Phase2TrackerDigi_> > &GenTrackInfoToken_ ,const edm::Event &iEvent, std::string Col, NtupleContent &nt);

  private:
    edm::Handle<std::vector< TTTrack<Ref_Phase2TrackerDigi_> >> L1Tracks;
    std::vector<unsigned int> passed_idxs;
    edm::Handle<TTTrackAssociationMap<Ref_Phase2TrackerDigi_>> MCTrkAssociation;

};

#endif
