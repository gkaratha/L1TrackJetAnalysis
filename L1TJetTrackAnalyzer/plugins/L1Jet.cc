#include "L1Jet.h"


L1Jet::L1Jet(){}

L1Jet::L1Jet (const edm::EDGetTokenT<std::vector<l1t::TkJet>> & JetToken_, const edm::Event & iEvent){
   iEvent.getByToken(JetToken_,Jets);
}

L1Jet::~L1Jet() {}

void
L1Jet::ReadData(const edm::EDGetTokenT<std::vector<l1t::TkJet>> & JetToken_, const edm::Event & iEvent){
  iEvent.getByToken(JetToken_,Jets);
}

void
L1Jet::FillBranches (std::string Col, NtupleContent &nt){
   unsigned int njets=0;
   for(const auto &jet: *Jets){
     //std::cout<<"in jet "<<jet.pt()<<std::endl;
     //nt.trackjet_pt.emplace_back(jet.pt());
     (nt.GetBranch(Col+"_pt"))->emplace_back(jet.pt());
     (nt.GetBranch(Col+"_eta"))->emplace_back(jet.eta());
     (nt.GetBranch(Col+"_phi"))->emplace_back(jet.phi());
     (nt.GetBranch(Col+"_nDispTracks"))->emplace_back(jet.nDisptracks());
     (nt.GetBranch(Col+"_nTightDispTracks"))->emplace_back(jet.nTightDisptracks());
     (nt.GetBranch(Col+"_nTracks"))->emplace_back(jet.ntracks());
     (nt.GetBranch(Col+"_nTightTracks"))->emplace_back(jet.nTighttracks());
     (nt.GetBranch(Col+"_nL1Trk"))->emplace_back(jet.trkPtrs().size());
      
     //std::cout<<"hg "<<jet.trkPtrs().size()<<std::endl;
     std::vector<float> vtrk_eta,vtrk_phi,vtrk_pt;
     for(auto &trkPtr: jet.trkPtrs() ){
        vtrk_eta.emplace_back(trkPtr->eta()); 
        vtrk_phi.emplace_back(trkPtr->phi());
        vtrk_pt.emplace_back(1./(trkPtr->rInv()));
     }
     (nt.Get2DBranch(Col+"_L1Trk_eta"))->emplace_back(vtrk_eta);
     (nt.Get2DBranch(Col+"_L1Trk_phi"))->emplace_back(vtrk_phi);
     (nt.Get2DBranch(Col+"_L1Trk_pt"))->emplace_back(vtrk_pt);
     njets+=1;
   }
   *(nt.SetNCol("n"+Col))=njets;
}

void 
L1Jet::AddMCBranches (std::string Col, NtupleContent &nt){
   for(unsigned int i=0; i<Jets->size(); i++)
     (nt.GetBranch(Col+"_matchedToGenIdx"))->emplace_back(-99);
     
   
}
