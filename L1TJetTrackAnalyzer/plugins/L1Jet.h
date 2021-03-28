#ifndef L1JET_H
#define L1JET_H
#include "NtupleContent.h"
#include <string>
#include <vector>
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/L1TCorrelator/interface/TkJet.h"
#include "DataFormats/L1TCorrelator/interface/TkJetFwd.h"

class L1Jet{
  public:
    L1Jet();
    L1Jet(const edm::EDGetTokenT<std::vector<l1t::TkJet>> & JetToken_, const edm::Event &iEvent);
    ~L1Jet();
    void ReadData(const edm::EDGetTokenT<std::vector<l1t::TkJet>> & JetToken_, const edm::Event &iEvent);
    void FillBranches(std::string Col, std::string ColTrk, NtupleContent &nt);
    void AddMCBranches(std::string Col, NtupleContent &nt);
  
  private:
    edm::Handle<std::vector<l1t::TkJet>> Jets;
   

};

#endif
