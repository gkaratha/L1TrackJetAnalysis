#ifndef NTUPLECONTENT_H
#define NTUPLECONTENT_H
#include <TTree.h>
#include <unordered_map>
#include <string>
#include <iostream>


class NtupleContent{
  public:
   explicit NtupleContent();
   ~NtupleContent();
   void SetTree(TTree *t1);
   void ClearBranches();
   void CreateBranches();
   std::vector<float>* GetBranch(std::string);
   std::vector<std::vector<int>>* Get2DBranch(std::string);
   unsigned int* SetNCol(std::string);
   float* GetScalarBranch(std::string name);

   std::vector<float> TwoLayerJet_pt, TwoLayerJet_eta, TwoLayerJet_phi,
                      TwoLayerJet_bx, TwoLayerJet_nDispTracks, 
                      TwoLayerJet_nTightDispTracks,
                      TwoLayerJet_nTightTracks, TwoLayerJet_matchedToGenIdx,
                      TwoLayerJet_nL1Trk, TwoLayerJet_matchedToTrackingJetIdx,
                      TwoLayerJet_matchedToGenDr, TwoLayerJet_matchedToTrackingJetDr;

   std::vector<std::vector<int>> TwoLayerJet_L1Trk_idx;

   std::vector<float> FastJet_pt, FastJet_eta, FastJet_phi,
                      FastJet_bx, FastJet_nDispTracks,
                      FastJet_nTightDispTracks,
                      FastJet_nTightTracks, FastJet_matchedToGenIdx,
                      FastJet_nL1Trk, FastJet_matchedToGenDr;

   std::vector<std::vector<int>> FastJet_L1Trk_idx;

   std::vector<float> TwoLayerJetExt_pt, TwoLayerJetExt_eta, TwoLayerJetExt_phi,
                      TwoLayerJetExt_bx, TwoLayerJetExt_nDispTracks,
                      TwoLayerJetExt_nTightDispTracks,
                      TwoLayerJetExt_nTightTracks, TwoLayerJetExt_matchedToGenIdx,
                      TwoLayerJetExt_nL1Trk,TwoLayerJetExt_matchedToTrackingJetExtIdx,
                      TwoLayerJetExt_matchedToGenDr, TwoLayerJetExt_matchedToTrackingJetExtDr;
   std::vector<std::vector<int>> TwoLayerJetExt_L1Trk_idx;


   std::vector<float> FastJetExt_pt, FastJetExt_eta, FastJetExt_phi,
                      FastJetExt_bx, FastJetExt_nDispTracks,
                      FastJetExt_nTightDispTracks,
                      FastJetExt_nTightTracks, FastJetExt_matchedToGenIdx,
                      FastJetExt_nL1Trk, FastJetExt_matchedToGenDr;

   std::vector<std::vector<int>> FastJetExt_L1Trk_idx;


   std::vector<float> TrackingJet_pt, TrackingJet_eta, TrackingJet_phi,
                      TrackingJet_bx, TrackingJet_nDispTracks,
                      TrackingJet_nTightDispTracks,
                      TrackingJet_nTightTracks, TrackingJet_matchedToGenIdx,
                      TrackingJet_nL1Trk,TrackingJet_matchedToTwoLayerJetIdx,
                      TrackingJet_matchedToGenDr,
                      TrackingJet_matchedToTwoLayerJetDr;

   std::vector<std::vector<int>> TrackingJet_L1Trk_idx;

   std::vector<float> TrackingJetExt_pt, TrackingJetExt_eta, TrackingJetExt_phi,
                      TrackingJetExt_bx, TrackingJetExt_nDispTracks,
                      TrackingJetExt_nTightDispTracks,TrackingJetExt_nTightTracks, 
                      TrackingJetExt_matchedToGenIdx, TrackingJetExt_nL1Trk,
                      TrackingJetExt_matchedToTwoLayerJetExtIdx,
                      TrackingJetExt_matchedToGenDr,
                      TrackingJetExt_matchedToTwoLayerJetExtDr;

   std::vector<std::vector<int>> TrackingJetExt_L1Trk_idx;


   std::vector<float> GenJet_pt, GenJet_eta, GenJet_phi,
                      GenJet_chargedEmE, GenJet_chargedHadronE,
                      GenJet_muonE, GenJet_neutralEmE, GenJet_neutralHadronE,
                      GenJet_matchedToFastJetIdx,GenJet_matchedToTwoLayerJetIdx,
                      GenJet_matchedToFastJetExtIdx,
                      GenJet_matchedToTwoLayerJetExtIdx,
                      GenJet_matchedToTrackingJetIdx,
                      GenJet_matchedToTrackingJetExtIdx,
                      GenJet_matchedToFastJetDr,GenJet_matchedToTwoLayerJetDr,
                      GenJet_matchedToFastJetExtDr,
                      GenJet_matchedToTwoLayerJetExtDr,
                      GenJet_matchedToTrackingJetDr,
                      GenJet_matchedToTrackingJetExtDr;

   std::vector<float> GenJet_part_pt, GenJet_part_eta, GenJet_part_phi,
                      GenJet_part_mass, GenJet_part_pdgId, GenJet_part_vx,
                      GenJet_part_vy, GenJet_part_vz, GenJet_part_dr,
                      GenJet_part_momPdgId, GenJet_part_d0,
                      GenJet_part_momPt, GenJet_part_momVx,
                      GenJet_part_momVy, GenJet_part_momVz;
 
   std::vector<float> Track_pt, Track_eta, Track_phi, Track_nFitPars,
                       Track_x0, Track_y0, Track_z0, Track_d0, Track_chi2, 
                       Track_chi2xy, Track_chi2z, Track_stubConsistency,
                       Track_isLooseGenuineMC, Track_isGenuineMC,
                       Track_isUnknownMC, Track_isCombinatoricMC,
                       Track_gen_pt, Track_gen_eta, Track_gen_phi,
                       Track_gen_pdgId,Track_gen_x0, Track_gen_y0, Track_gen_z0,
                       Track_gen_dxy, Track_gen_d0;
    std::vector<float> TrackExt_pt, TrackExt_eta, TrackExt_phi, TrackExt_nFitPars,
                       TrackExt_x0, TrackExt_y0, TrackExt_z0, TrackExt_d0, TrackExt_chi2,
                       TrackExt_chi2xy, TrackExt_chi2z, TrackExt_stubConsistency,
                       TrackExt_isLooseGenuineMC, TrackExt_isGenuineMC,
                       TrackExt_isUnknownMC, TrackExt_isCombinatoricMC,
                       TrackExt_gen_pt, TrackExt_gen_eta, TrackExt_gen_phi,
                       TrackExt_gen_pdgId,TrackExt_gen_x0, TrackExt_gen_y0, TrackExt_gen_z0,
                       TrackExt_gen_dxy, TrackExt_gen_d0;
   
   std::vector<float> PV_z0, PV_sum;

   float RunNumber,LumiSection, EventNumber, Beamspot_x, Beamspot_y, Beamspot_z;
   // 
   unsigned int nTwoLayerJet, nFastJet, nGenJet, nTrack, nTrackExt,
                nTwoLayerJetExt, nFastJetExt, nPV, nTrackingJet, nTrackingJetExt;
   float MET_et,MET_phi,MET_etTotal,MHT_etTotal,MHT_et,MHT_phi;

   std::map<std::string, std::vector<float>* > variable_map;
   std::map<std::string, std::vector<std::vector<int>>* > variable_2d_map;
   std::map<std::string, unsigned int*> nCol_map;
   std::map<std::string, float*> variable_scalar_map;


 private:
   TTree *mytree;


};

#endif
