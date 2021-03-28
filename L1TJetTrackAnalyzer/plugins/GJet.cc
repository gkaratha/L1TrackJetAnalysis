#include "GJet.h"
#include <iostream>

GJet::GJet(const edm::EDGetTokenT<std::vector<reco::GenJet>> &GenToken_, const edm::EDGetTokenT<std::vector<reco::GenParticle>> &GenPartToken_, const edm::Event &iEvent){
  iEvent.getByToken(GenToken_,gJets);
  iEvent.getByToken(GenPartToken_,gParts);
}

GJet::~GJet(){}

void
GJet::FillBranches(NtupleContent &nt){
  auto null_value=gJets->size()+1000;
  long unsigned int jet_parton[gJets->size()]={null_value};
  float jet_parton_mindr[gJets->size()]={-1};
  for (auto & gPart: *gParts){
    if( !gPart.isLastCopy() || !gPart.isHardProcess()) continue;
    for (unsigned int idaughter=0; idaughter<gPart.numberOfDaughters(); idaughter++){
      const reco::Candidate* daughterPart = gPart.daughter(idaughter);
      float minDR=100;
      unsigned int jet_idx=null_value;
      for( auto & gJet: *gJets){
        float DR=reco::deltaR2(gJet.eta(),gJet.phi(),daughterPart->eta(),daughterPart->phi());
        if (minDR<DR) continue;
        minDR=DR;
        jet_idx=&gJet-&(gJets->at(0));
      }
      jet_parton[jet_idx] = gPart.daughterRef(idaughter).key();     
      jet_parton_mindr[jet_idx] = minDR;
    }
  }
    
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
    (nt.GenJet_matchedToTwoLayerJetIdx).emplace_back(-99.);
    (nt.GenJet_matchedToFastJetExtIdx).emplace_back(-99.);
    (nt.GenJet_matchedToTwoLayerJetExtIdx).emplace_back(-99.);
    (nt.GenJet_matchedToTrackingJetIdx).emplace_back(-99.);
    (nt.GenJet_matchedToTrackingJetExtIdx).emplace_back(-99.);
    
    if (jet_parton[ &gJet -&gJets->at(0)]!=null_value){
      reco::GenParticle genPart= gParts->at(jet_parton[ &gJet -&gJets->at(0)]);
      (nt.GenJet_part_pt).emplace_back(genPart.pt());
      (nt.GenJet_part_eta).emplace_back(genPart.eta());
      (nt.GenJet_part_phi).emplace_back(genPart.phi());
      (nt.GenJet_part_mass).emplace_back(genPart.mass());
      (nt.GenJet_part_pdgId).emplace_back(genPart.pdgId());
      (nt.GenJet_part_vx).emplace_back(genPart.vx());
      (nt.GenJet_part_vy).emplace_back(genPart.vy());
      (nt.GenJet_part_vz).emplace_back(genPart.vz());
      (nt.GenJet_part_d0).emplace_back(-genPart.vx()*sin(genPart.phi())+genPart.vy()*cos(genPart.phi()));
      if (genPart.numberOfMothers()>0)
        (nt.GenJet_part_momPdgId).emplace_back(genPart.mother(0)->pdgId());
      else
        (nt.GenJet_part_momPdgId).emplace_back(-99);
      (nt.GenJet_part_dr).emplace_back(jet_parton_mindr[ &gJet -&gJets->at(0)]);
      
    } else {
      (nt.GenJet_part_dr).emplace_back(100);
      (nt.GenJet_part_pt).emplace_back(-99);
      (nt.GenJet_part_eta).emplace_back(-99);
      (nt.GenJet_part_phi).emplace_back(-99);
      (nt.GenJet_part_mass).emplace_back(-99);
      (nt.GenJet_part_pdgId).emplace_back(-99);
      (nt.GenJet_part_vx).emplace_back(-99);
      (nt.GenJet_part_vy).emplace_back(-99);
      (nt.GenJet_part_vz).emplace_back(-99);
      (nt.GenJet_part_momPdgId).emplace_back(-99);
     }
    //(nt.GenJet_part_status).emplace_back(minDR);
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
