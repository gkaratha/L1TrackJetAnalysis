#include "NtupleContent.h"
#include <unordered_map>


NtupleContent::NtupleContent(){
  variable_map["TrackJet_pt"]=&TrackJet_pt; 
  variable_map["TrackJet_eta"]=&TrackJet_eta;
  variable_map["TrackJet_phi"]=&TrackJet_phi;
  variable_map["TrackJet_nDispTracks"]=&TrackJet_nDispTracks;
  variable_map["TrackJet_nTightDispTracks"]=&TrackJet_nTightDispTracks;
  variable_map["TrackJet_nTracks"]=&TrackJet_nTracks;
  variable_map["TrackJet_nTightTracks"]=&TrackJet_nTightTracks;
  variable_map["TrackJet_matchedToGenIdx"]=&TrackJet_matchedToGenIdx;
  variable_map["TrackJet_nL1Trk"]=&TrackJet_nL1Trk;
  variable_2d_map["TrackJet_L1Trk_pt"]=&TrackJet_L1Trk_pt; 
  variable_2d_map["TrackJet_L1Trk_eta"]=&TrackJet_L1Trk_eta;
  variable_2d_map["TrackJet_L1Trk_phi"]=&TrackJet_L1Trk_phi;
  nCol_map["nTrackJet"]=&nTrackJet;
  variable_map["FastJet_pt"]=&FastJet_pt;
  variable_map["FastJet_eta"]=&FastJet_eta;
  variable_map["FastJet_phi"]=&FastJet_phi;
  variable_map["FastJet_nDispTracks"]=&FastJet_nDispTracks;
  variable_map["FastJet_nTightDispTracks"]=&FastJet_nTightDispTracks;
  variable_map["FastJet_nTracks"]=&FastJet_nTracks;
  variable_map["FastJet_nTightTracks"]=&FastJet_nTightTracks;
  variable_map["FastJet_matchedToGenIdx"]=&FastJet_matchedToGenIdx;
  variable_map["FastJet_nL1Trk"]=&FastJet_nL1Trk;
  variable_2d_map["FastJet_L1Trk_pt"]=&FastJet_L1Trk_pt;
  variable_2d_map["FastJet_L1Trk_eta"]=&FastJet_L1Trk_eta;
  variable_2d_map["FastJet_L1Trk_phi"]=&FastJet_L1Trk_phi;
  nCol_map["nFastJet"]=&nFastJet;
  variable_map["TrackJetExt_pt"]=&TrackJetExt_pt;
  variable_map["TrackJetExt_eta"]=&TrackJetExt_eta;
  variable_map["TrackJetExt_phi"]=&TrackJetExt_phi;
  variable_map["TrackJetExt_nDispTracks"]=&TrackJetExt_nDispTracks;
  variable_map["TrackJetExt_nTightDispTracks"]=&TrackJetExt_nTightDispTracks;
  variable_map["TrackJetExt_nTracks"]=&TrackJetExt_nTracks;
  variable_map["TrackJetExt_nTightTracks"]=&TrackJetExt_nTightTracks;
  variable_map["TrackJetExt_matchedToGenIdx"]=&TrackJetExt_matchedToGenIdx;
  variable_map["TrackJetExt_nL1Trk"]=&TrackJetExt_nL1Trk;
  variable_2d_map["TrackJetExt_L1Trk_pt"]=&TrackJetExt_L1Trk_pt;
  variable_2d_map["TrackJetExt_L1Trk_eta"]=&TrackJetExt_L1Trk_eta;
  variable_2d_map["TrackJetExt_L1Trk_phi"]=&TrackJetExt_L1Trk_phi;
  nCol_map["nTrackJetExt"]=&nTrackJetExt;
  variable_map["FastJetExt_pt"]=&FastJetExt_pt;
  variable_map["FastJetExt_eta"]=&FastJetExt_eta;
  variable_map["FastJetExt_phi"]=&FastJetExt_phi;
  variable_map["FastJetExt_nDispTracks"]=&FastJetExt_nDispTracks;
  variable_map["FastJetExt_nTightDispTracks"]=&FastJetExt_nTightDispTracks;
  variable_map["FastJetExt_nTracks"]=&FastJetExt_nTracks;
  variable_map["FastJetExt_nTightTracks"]=&FastJetExt_nTightTracks;
  variable_map["FastJetExt_matchedToGenIdx"]=&FastJetExt_matchedToGenIdx;
  variable_map["FastJetExt_nL1Trk"]=&FastJetExt_nL1Trk;
  variable_2d_map["FastJetExt_L1Trk_pt"]=&FastJetExt_L1Trk_pt;
  variable_2d_map["FastJetExt_L1Trk_eta"]=&FastJetExt_L1Trk_eta;
  variable_2d_map["FastJetExt_L1Trk_phi"]=&FastJetExt_L1Trk_phi;
  nCol_map["nFastJetExt"]=&nFastJetExt;

  variable_map["GenJet_pt"]=&GenJet_pt;
  variable_map["GenJet_eta"]=&GenJet_eta;
  variable_map["GenJet_phi"]=&GenJet_phi;
  variable_map["GenJet_chargedEmE"]=&GenJet_chargedEmE;
  variable_map["GenJet_chargedHadronE"]=&GenJet_chargedHadronE;
  variable_map["GenJet_muonE"]=&GenJet_muonE;
  variable_map["GenJet_neutralEmE"]=&GenJet_neutralEmE;
  variable_map["GenJet_neutralHadronE"]=&GenJet_neutralHadronE;
  variable_map["GenJet_matchedToFastJetIdx"]=&GenJet_matchedToFastJetIdx;
  variable_map["GenJet_matchedToTrackJetIdx"]=&GenJet_matchedToTrackJetIdx;
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
  return variable_map[name];
}

std::vector<std::vector<float>>*
NtupleContent::Get2DBranch(std::string name){
  return variable_2d_map[name];
}

float*
NtupleContent::GetScalarBranch(std::string name){
  return variable_scalar_map[name];
}

unsigned int*
NtupleContent::SetNCol(std::string name){
  return nCol_map[name];
}
