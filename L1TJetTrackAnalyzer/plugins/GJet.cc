#include "GJet.h"

GJet::GJet(const edm::EDGetTokenT<std::vector<reco::GenJet>> &GenToken_,const edm::Event &iEvent){
  iEvent.getByToken(GenToken_,gJets);
}

GJet::~GJet(){}

void
GJet::FillBranches(NtupleContent &nt){
  for( auto & gJet: *gJets){
    (nt.GenJet_pt).emplace_back(gJet.pt());
    (nt.GenJet_eta).emplace_back(gJet.eta());
    (nt.GenJet_phi).emplace_back(gJet.phi());
    (nt.GenJet_chargedEmE).emplace_back(gJet.chargedEmEnergy() );
    (nt.GenJet_chargedHadronE).emplace_back(gJet.chargedHadronEnergy());
    (nt.GenJet_muonE).emplace_back(gJet.muonEnergy());
    (nt.GenJet_neutralEmE).emplace_back(gJet.neutralEmEnergy());
    (nt.GenJet_neutralHadronE).emplace_back(gJet.neutralHadronEnergy());
    (nt.GenJet_matchedToFastJetIdx).emplace_back(-99.);
    (nt.GenJet_matchedToTrackJetIdx).emplace_back(-99.);
  }
}

void
GJet::MatchToReco(std::string Col, float boundDR, NtupleContent &nt){
  for(unsigned int igen=0; igen<nt.GenJet_pt.size(); igen++){
     float minDR2=100,imatch=-1;
     for( unsigned int ireco=0; ireco<(nt.GetBranch(Col+"_pt"))->size(); ireco++){
       if ( minDR2<reco::deltaR2(nt.GenJet_eta[igen],nt.GenJet_phi[igen],(nt.GetBranch(Col+"_eta"))->at(ireco),(nt.GetBranch(Col+"_phi"))->at(ireco) ) )
          continue;
       minDR2=reco::deltaR2(nt.GenJet_eta[igen],nt.GenJet_phi[igen],(nt.GetBranch(Col+"_eta"))->at(ireco),(nt.GetBranch(Col+"_phi"))->at(ireco) );
       imatch=ireco;
     }
     if (minDR2>boundDR*boundDR) continue;
     nt.GetBranch("GenJet_matchedTo"+Col+"Idx")->at(igen)=imatch;
     nt.GetBranch(Col+"_matchedToGenIdx")->at(imatch)=igen; 
  }
}
