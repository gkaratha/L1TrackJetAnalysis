#include "NtupleContent.h"
#include <unordered_map>


NtupleContent::NtupleContent(){
  variable_map["TwoLayerJet_pt"]=&TwoLayerJet_pt; 
  variable_map["TwoLayerJet_eta"]=&TwoLayerJet_eta;
  variable_map["TwoLayerJet_phi"]=&TwoLayerJet_phi;
  variable_map["TwoLayerJet_nDispTracks"]=&TwoLayerJet_nDispTracks;
  variable_map["TwoLayerJet_nTightDispTracks"]=&TwoLayerJet_nTightDispTracks;
  variable_map["TwoLayerJet_nTightTracks"]=&TwoLayerJet_nTightTracks;
  variable_map["TwoLayerJet_matchedToGenIdx"]=&TwoLayerJet_matchedToGenIdx;
  variable_map["TwoLayerJet_matchedToGenDr"]=&TwoLayerJet_matchedToGenDr;
  variable_map["TwoLayerJet_nL1Trk"]=&TwoLayerJet_nL1Trk;
  variable_map["TwoLayerJet_matchedToTrackingJetIdx"]=&TwoLayerJet_matchedToTrackingJetIdx;
  variable_map["TwoLayerJet_matchedToTrackingJetDr"]=&TwoLayerJet_matchedToTrackingJetDr;
  variable_2d_map["TwoLayerJet_L1Trk_idx"]=&TwoLayerJet_L1Trk_idx; 
  nCol_map["nTwoLayerJet"]=&nTwoLayerJet;
  variable_map["FastJet_pt"]=&FastJet_pt;
  variable_map["FastJet_eta"]=&FastJet_eta;
  variable_map["FastJet_phi"]=&FastJet_phi;
  variable_map["FastJet_nDispTracks"]=&FastJet_nDispTracks;
  variable_map["FastJet_nTightDispTracks"]=&FastJet_nTightDispTracks;
  variable_map["FastJet_nTightTracks"]=&FastJet_nTightTracks;
  variable_map["FastJet_matchedToGenIdx"]=&FastJet_matchedToGenIdx;
  variable_map["FastJet_matchedToGenDr"]=&FastJet_matchedToGenDr;
  variable_map["FastJet_nL1Trk"]=&FastJet_nL1Trk;
  variable_2d_map["FastJet_L1Trk_idx"]=&FastJet_L1Trk_idx;
  nCol_map["nFastJet"]=&nFastJet;
  variable_map["TwoLayerJetExt_pt"]=&TwoLayerJetExt_pt;
  variable_map["TwoLayerJetExt_eta"]=&TwoLayerJetExt_eta;
  variable_map["TwoLayerJetExt_phi"]=&TwoLayerJetExt_phi;
  variable_map["TwoLayerJetExt_nDispTracks"]=&TwoLayerJetExt_nDispTracks;
  variable_map["TwoLayerJetExt_nTightDispTracks"]=&TwoLayerJetExt_nTightDispTracks;
  variable_map["TwoLayerJetExt_nTightTracks"]=&TwoLayerJetExt_nTightTracks;
  variable_map["TwoLayerJetExt_matchedToGenIdx"]=&TwoLayerJetExt_matchedToGenIdx;
  variable_map["TwoLayerJetExt_matchedToGenDr"]=&TwoLayerJetExt_matchedToGenDr;
  variable_map["TwoLayerJetExt_nL1Trk"]=&TwoLayerJetExt_nL1Trk;
  variable_map["TwoLayerJetExt_matchedToTrackingJetExtIdx"]=&TwoLayerJetExt_matchedToTrackingJetExtIdx;
  variable_map["TwoLayerJetExt_matchedToTrackingJetExtDr"]=&TwoLayerJetExt_matchedToTrackingJetExtDr;

  variable_2d_map["TwoLayerJetExt_L1Trk_idx"]=&TwoLayerJetExt_L1Trk_idx;
  nCol_map["nTwoLayerJetExt"]=&nTwoLayerJetExt;
  variable_map["FastJetExt_pt"]=&FastJetExt_pt;
  variable_map["FastJetExt_eta"]=&FastJetExt_eta;
  variable_map["FastJetExt_phi"]=&FastJetExt_phi;
  variable_map["FastJetExt_nDispTracks"]=&FastJetExt_nDispTracks;
  variable_map["FastJetExt_nTightDispTracks"]=&FastJetExt_nTightDispTracks;
  variable_map["FastJetExt_nTightTracks"]=&FastJetExt_nTightTracks;
  variable_map["FastJetExt_matchedToGenIdx"]=&FastJetExt_matchedToGenIdx;
  variable_map["FastJetExt_matchedToGenDr"]=&FastJetExt_matchedToGenDr;
  variable_map["FastJetExt_nL1Trk"]=&FastJetExt_nL1Trk;
  variable_2d_map["FastJetExt_L1Trk_idx"]=&FastJetExt_L1Trk_idx;
  nCol_map["nFastJetExt"]=&nFastJetExt;
  variable_map["TrackingJetExt_pt"]=&TrackingJetExt_pt;
  variable_map["TrackingJetExt_eta"]=&TrackingJetExt_eta;
  variable_map["TrackingJetExt_phi"]=&TrackingJetExt_phi;
  variable_map["TrackingJetExt_nDispTracks"]=&TrackingJetExt_nDispTracks;
  variable_map["TrackingJetExt_nTightDispTracks"]=&TrackingJetExt_nTightDispTracks;
  variable_map["TrackingJetExt_nTightTracks"]=&TrackingJetExt_nTightTracks;
  variable_map["TrackingJetExt_matchedToGenIdx"]=&TrackingJetExt_matchedToGenIdx;
  variable_map["TrackingJetExt_matchedToGenDr"]=&TrackingJetExt_matchedToGenDr;

  variable_map["TrackingJetExt_nL1Trk"]=&TrackingJetExt_nL1Trk;
  variable_map["TrackingJetExt_matchedToTwoLayerJetExtIdx"]=&TrackingJetExt_matchedToTwoLayerJetExtIdx;
  variable_map["TrackingJetExt_matchedToTwoLayerJetExtDr"]=&TrackingJetExt_matchedToTwoLayerJetExtDr;
  variable_2d_map["TrackingJetExt_L1Trk_idx"]=&TrackingJetExt_L1Trk_idx;
  nCol_map["nTrackingJetExt"]=&nTrackingJetExt;
  variable_map["TrackingJet_pt"]=&TrackingJet_pt;
  variable_map["TrackingJet_eta"]=&TrackingJet_eta;
  variable_map["TrackingJet_phi"]=&TrackingJet_phi;
  variable_map["TrackingJet_nDispTracks"]=&TrackingJet_nDispTracks;
  variable_map["TrackingJet_nTightDispTracks"]=&TrackingJet_nTightDispTracks;
  variable_map["TrackingJet_nTightTracks"]=&TrackingJet_nTightTracks;
  variable_map["TrackingJet_matchedToGenIdx"]=&TrackingJet_matchedToGenIdx;
  variable_map["TrackingJet_matchedToGenDr"]=&TrackingJet_matchedToGenDr;
  variable_map["TrackingJet_nL1Trk"]=&TrackingJet_nL1Trk;
  variable_map["TrackingJet_matchedToTwoLayerJetIdx"]=&TrackingJet_matchedToTwoLayerJetIdx;
  variable_map["TrackingJet_matchedToTwoLayerJetDr"]=&TrackingJet_matchedToTwoLayerJetDr;
  variable_2d_map["TrackingJet_L1Trk_idx"]=&TrackingJet_L1Trk_idx;
  nCol_map["nTrackingJet"]=&nTrackingJet;
  variable_map["GenJet_pt"]=&GenJet_pt;
  variable_map["GenJet_eta"]=&GenJet_eta;
  variable_map["GenJet_phi"]=&GenJet_phi;
  variable_map["GenJet_chargedEmE"]=&GenJet_chargedEmE;
  variable_map["GenJet_chargedHadronE"]=&GenJet_chargedHadronE;
  variable_map["GenJet_muonE"]=&GenJet_muonE;
  variable_map["GenJet_neutralEmE"]=&GenJet_neutralEmE;
  variable_map["GenJet_neutralHadronE"]=&GenJet_neutralHadronE;
  variable_map["GenJet_matchedToFastJetIdx"]=&GenJet_matchedToFastJetIdx;
  variable_map["GenJet_matchedToFastJetDr"]=&GenJet_matchedToFastJetDr;
  variable_map["GenJet_matchedToTwoLayerJetIdx"]=&GenJet_matchedToTwoLayerJetIdx;
  variable_map["GenJet_matchedToTwoLayerJetDr"]=&GenJet_matchedToTwoLayerJetDr;
  variable_map["GenJet_matchedToFastJetExtIdx"]=&GenJet_matchedToFastJetExtIdx;
  variable_map["GenJet_matchedToFastJetExtDr"]=&GenJet_matchedToFastJetExtDr;
  variable_map["GenJet_matchedToTwoLayerJetExtIdx"]=&GenJet_matchedToTwoLayerJetExtIdx;
  variable_map["GenJet_matchedToTwoLayerJetExtDr"]=&GenJet_matchedToTwoLayerJetExtDr;
  variable_map["GenJet_matchedToTrackingJetIdx"]=&GenJet_matchedToTrackingJetIdx;
  variable_map["GenJet_matchedToTrackingJetDr"]=&GenJet_matchedToTrackingJetDr;
  variable_map["GenJet_matchedToTrackingJetExtIdx"]=&GenJet_matchedToTrackingJetExtIdx;
  variable_map["GenJet_matchedToTrackingJetExtDr"]=&GenJet_matchedToTrackingJetExtDr;
  variable_map["GenJet_part_pt"]=&GenJet_part_pt;
  variable_map["GenJet_part_eta"]=&GenJet_part_eta;
  variable_map["GenJet_part_phi"]=&GenJet_part_phi;
  variable_map["GenJet_part_mass"]=&GenJet_part_mass;
  variable_map["GenJet_part_pdgId"]=&GenJet_part_pdgId;
  variable_map["GenJet_part_vx"]=&GenJet_part_vx;
  variable_map["GenJet_part_vy"]=&GenJet_part_vy;
  variable_map["GenJet_part_vz"]=&GenJet_part_vz;
  variable_map["GenJet_part_dr"]=&GenJet_part_dr;
  variable_map["GenJet_part_d0"]=&GenJet_part_d0;
  variable_map["GenJet_part_momPdgId"]=&GenJet_part_momPdgId;
  variable_map["GenJet_part_momPt"]=&GenJet_part_momPt;
  variable_map["GenJet_part_momVx"]=&GenJet_part_momVx;
  variable_map["GenJet_part_momVy"]=&GenJet_part_momVy;
  variable_map["GenJet_part_momVz"]=&GenJet_part_momVz;
  nCol_map["nGenJet"]=&nGenJet;
  variable_map["Track_pt"]=&Track_pt;
  variable_map["Track_eta"]=&Track_eta;
  variable_map["Track_phi"]=&Track_phi;
  variable_map["Track_nFitPars"]=&Track_nFitPars;
  variable_map["Track_x0"]=&Track_x0;
  variable_map["Track_y0"]=&Track_y0;
  variable_map["Track_z0"]=&Track_z0;
  variable_map["Track_d0"]=&Track_d0;
  variable_map["Track_chi2"]=&Track_chi2;
  variable_map["Track_chi2xy"]=&Track_chi2xy;
  variable_map["Track_chi2z"]=&Track_chi2z;
  variable_map["Track_stubConsistency"]=&Track_stubConsistency;
  variable_map["Track_gen_pt"]=&Track_gen_pt;
  variable_map["Track_gen_eta"]=&Track_gen_eta;
  variable_map["Track_gen_phi"]=&Track_gen_phi;
  variable_map["Track_gen_x0"]=&Track_gen_x0;
  variable_map["Track_gen_y0"]=&Track_gen_y0;
  variable_map["Track_gen_z0"]=&Track_gen_z0;
  variable_map["Track_gen_dxy"]=&Track_gen_dxy;
  variable_map["Track_gen_d0"]=&Track_gen_d0;
  variable_map["Track_gen_pdgId"]=&Track_gen_pdgId;
  variable_map["Track_isLooseGenuineMC"]=&Track_isLooseGenuineMC;
  variable_map["Track_isGenuineMC"]=&Track_isGenuineMC;
  variable_map["Track_isUnknownMC"]=&Track_isUnknownMC;
  variable_map["Track_isCombinatoricMC"]=&Track_isCombinatoricMC;
  nCol_map["nTrack"]=&nTrack;
  variable_map["TrackExt_pt"]=&TrackExt_pt;
  variable_map["TrackExt_eta"]=&TrackExt_eta;
  variable_map["TrackExt_phi"]=&TrackExt_phi;
  variable_map["TrackExt_nFitPars"]=&TrackExt_nFitPars;
  variable_map["TrackExt_x0"]=&TrackExt_x0;
  variable_map["TrackExt_y0"]=&TrackExt_y0;
  variable_map["TrackExt_z0"]=&TrackExt_z0;
  variable_map["TrackExt_d0"]=&TrackExt_d0;
  variable_map["TrackExt_chi2"]=&TrackExt_chi2;
  variable_map["TrackExt_chi2xy"]=&TrackExt_chi2xy;
  variable_map["TrackExt_chi2z"]=&TrackExt_chi2z;
  variable_map["TrackExt_stubConsistency"]=&TrackExt_stubConsistency;
  variable_map["TrackExt_gen_pt"]=&TrackExt_gen_pt;
  variable_map["TrackExt_gen_eta"]=&TrackExt_gen_eta;
  variable_map["TrackExt_gen_phi"]=&TrackExt_gen_phi;
  variable_map["TrackExt_gen_x0"]=&TrackExt_gen_x0;
  variable_map["TrackExt_gen_y0"]=&TrackExt_gen_y0;
  variable_map["TrackExt_gen_z0"]=&TrackExt_gen_z0;
  variable_map["TrackExt_gen_dxy"]=&TrackExt_gen_dxy;
  variable_map["TrackExt_gen_d0"]=&TrackExt_gen_d0;
  variable_map["TrackExt_gen_pdgId"]=&TrackExt_gen_pdgId;
  variable_map["TrackExt_isLooseGenuineMC"]=&TrackExt_isLooseGenuineMC;
  variable_map["TrackExt_isGenuineMC"]=&TrackExt_isGenuineMC;
  variable_map["TrackExt_isUnknownMC"]=&TrackExt_isUnknownMC;
  variable_map["TrackExt_isCombinatoricMC"]=&TrackExt_isCombinatoricMC;
  nCol_map["nTrackExt"]=&nTrackExt;
  variable_map["PV_sum"]=&PV_sum;
  variable_map["PV_z0"]=&PV_z0;
  nCol_map["nPV"]=&nPV;
  variable_scalar_map["MET_et"]=&MET_et;
  variable_scalar_map["MET_phi"]=&MET_phi;
  variable_scalar_map["MET_etTotal"]=&MET_etTotal;
  variable_scalar_map["MHT_et"]=&MHT_et;
  variable_scalar_map["MHT_phi"]=&MHT_phi;
  variable_scalar_map["MHT_etTotal"]=&MHT_etTotal;
  variable_scalar_map["RunNumber"]=&RunNumber;
  variable_scalar_map["EventNumber"]=&EventNumber;
  variable_scalar_map["LumiSection"]=&LumiSection;
  variable_scalar_map["Beamspot_x"]=&Beamspot_x;
  variable_scalar_map["Beamspot_y"]=&Beamspot_y;
  variable_scalar_map["Beamspot_z"]=&Beamspot_z;
 };

NtupleContent::~NtupleContent(){};

void
NtupleContent::ClearBranches(){
 for( auto variable: variable_map)
   variable.second->clear();
 for( auto variable: variable_2d_map)
   variable.second->clear();
 for(auto variable: nCol_map)
   (*variable.second)=0;
 for( auto variable: variable_scalar_map)
   (*variable.second)=0;

}

void
NtupleContent::SetTree(TTree *t1){
 mytree=t1;
}

void
NtupleContent::CreateBranches(){
 for( auto variable: variable_map)
    mytree->Branch(variable.first.c_str(),variable.second);
 for( auto nCol: nCol_map)
    mytree->Branch(nCol.first.c_str(),nCol.second);
 for( auto variable: variable_2d_map)
    mytree->Branch(variable.first.c_str(),variable.second);
 for( auto variable: variable_scalar_map)
    mytree->Branch(variable.first.c_str(),variable.second);
}

std::vector<float>*
NtupleContent::GetBranch(std::string name){
  bool exist=false;
  for(auto var:variable_map)
    if (name==var.first.c_str()){
      exist=true;
      break;
    }
  if (!exist) std::cout<<"problem in var "<<name<<std::endl;

  return variable_map[name];
}

std::vector<std::vector<int>>*
NtupleContent::Get2DBranch(std::string name){
  bool exist=false;
  for(auto var:variable_2d_map) 
    if (name==var.first.c_str()){
      exist=true;
      break;
    }
  if (!exist) std::cout<<"problem in var "<<name<<std::endl;
  return variable_2d_map[name];
}

float*
NtupleContent::GetScalarBranch(std::string name){
  bool exist=false;
  for(auto var:variable_scalar_map)
    if (name==var.first.c_str()){
      exist=true;
      break;
    }
  if (!exist) std::cout<<"problem in var "<<name<<std::endl;

  return variable_scalar_map[name];
}

unsigned int*
NtupleContent::SetNCol(std::string name){
  bool exist=false;
  for(auto var:nCol_map)
    if (name==var.first.c_str()){
      exist=true;
      break;
    }
  if (!exist) std::cout<<"problem in var "<<name<<std::endl;

  return nCol_map[name];
}
