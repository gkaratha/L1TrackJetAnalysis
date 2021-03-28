#ifndef GENJET_H
#define GENJET_H
#include "NtupleContent.h"
#include <string>
#include <vector>
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"



class GJet{
  public:
   GJet(const edm::EDGetTokenT<std::vector<reco::GenJet>> &, const edm::EDGetTokenT<std::vector<reco::GenParticle>> &, const edm::Event &);
   ~GJet();

  void FillBranches(NtupleContent &nt);
  void MatchToReco(std::string Col, float boundDR, NtupleContent &nt);

  private:
   edm::Handle<std::vector<reco::GenJet>> gJets;
   edm::Handle<std::vector<reco::GenParticle>> gParts;
};

#endif
