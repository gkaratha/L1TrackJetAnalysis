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
L1Jet::FillBranches (std::string Col, std::string ColTrk, NtupleContent &nt){
   unsigned int njets=0;
   for(const auto &jet: *Jets){
     
     (nt.GetBranch(Col+"_pt"))->emplace_back(jet.pt());
     (nt.GetBranch(Col+"_eta"))->emplace_back(jet.eta());
     (nt.GetBranch(Col+"_phi"))->emplace_back(jet.phi());
     (nt.GetBranch(Col+"_nDispTracks"))->emplace_back(jet.nDisptracks());
     (nt.GetBranch(Col+"_nTightDispTracks"))->emplace_back(jet.nTightDisptracks());
     (nt.GetBranch(Col+"_nTightTracks"))->emplace_back(jet.nTighttracks());
     (nt.GetBranch(Col+"_nL1Trk"))->emplace_back(jet.trkPtrs().size());
     
     std::vector<int> vtrk_idx;
     for(auto &trkPtr: jet.trkPtrs() ){
        int idx=-99;
        for(unsigned int itrk=0; itrk<nt.GetBranch(ColTrk+"_pt")->size(); itrk++){
          if ( fabs(trkPtr->eta()-nt.GetBranch(ColTrk+"_eta")->at(itrk))>0.00001 || fabs(trkPtr->phi()-nt.GetBranch(ColTrk+"_phi")->at(itrk))>0.00001 )
              continue;
          idx=itrk;
          break; 
        }
        vtrk_idx.emplace_back(idx); 
     }
     (nt.Get2DBranch(Col+"_L1Trk_idx"))->emplace_back(vtrk_idx);
     njets+=1;
   }
   *(nt.SetNCol("n"+Col))=njets;
}

void 
L1Jet::AddMCBranches (std::string Col, NtupleContent &nt){
   for(unsigned int i=0; i<Jets->size(); i++)
     (nt.GetBranch(Col+"_matchedToGenIdx"))->emplace_back(-99);
     
   
}
