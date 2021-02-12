#ifndef NTUPLECONTENT_H
#define NTUPLECONTENT_H
#include <TTree.h>
#include <unordered_map>
#include <string>

class NtupleContent{
  public:
   explicit NtupleContent();
   ~NtupleContent();
   void SetTree(TTree *t1);
   void ClearBranches();
   void CreateBranches();
   std::vector<float>* GetBranch(std::string);
   std::vector<std::vector<float>>* Get2DBranch(std::string);
   unsigned int* SetNCol(std::string);
   float* GetScalarBranch(std::string name);

   std::vector<float> TrackJet_pt, TrackJet_eta, TrackJet_phi,
                      TrackJet_bx, TrackJet_nDispTracks, 
                      TrackJet_nTightDispTracks, TrackJet_nTracks,
                      TrackJet_nTightTracks, TrackJet_matchedToGenIdx,
                      TrackJet_nL1Trk;

   std::vector<std::vector<float>> TrackJet_L1Trk_pt, TrackJet_L1Trk_eta,
                                   TrackJet_L1Trk_phi;

   std::vector<float> FastJet_pt, FastJet_eta, FastJet_phi,
                      FastJet_bx, FastJet_nDispTracks,
                      FastJet_nTightDispTracks, FastJet_nTracks,
                      FastJet_nTightTracks, FastJet_matchedToGenIdx,
                      FastJet_nL1Trk;

   std::vector<std::vector<float>> FastJet_L1Trk_pt, FastJet_L1Trk_eta,
                                   FastJet_L1Trk_phi;

   std::vector<float> TrackJetExt_pt, TrackJetExt_eta, TrackJetExt_phi,
                      TrackJetExt_bx, TrackJetExt_nDispTracks,
                      TrackJetExt_nTightDispTracks, TrackJetExt_nTracks,
                      TrackJetExt_nTightTracks, TrackJetExt_matchedToGenIdx,
                      TrackJetExt_nL1Trk;

   std::vector<std::vector<float>> TrackJetExt_L1Trk_pt, TrackJetExt_L1Trk_eta,
                                   TrackJetExt_L1Trk_phi;


   std::vector<float> FastJetExt_pt, FastJetExt_eta, FastJetExt_phi,
                      FastJetExt_bx, FastJetExt_nDispTracks,
                      FastJetExt_nTightDispTracks, FastJetExt_nTracks,
                      FastJetExt_nTightTracks, FastJetExt_matchedToGenIdx,
                      FastJetExt_nL1Trk;

   std::vector<std::vector<float>> FastJetExt_L1Trk_pt, FastJetExt_L1Trk_eta,
                                   FastJetExt_L1Trk_phi;


   std::vector<float> GenJet_pt, GenJet_eta, GenJet_phi,
                      GenJet_chargedEmE, GenJet_chargedHadronE,
                      GenJet_muonE, GenJet_neutralEmE, GenJet_neutralHadronE,
                      GenJet_matchedToFastJetIdx,GenJet_matchedToTrackJetIdx;
 
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
   
   std::vector<float> PV_z0,PV_sum;
   // 
   unsigned int nTrackJet, nFastJet, nGenJet, nTrack, nTrackExt, nTrackJetExt,
                nFastJetExt, nPV;
   float MET_et,MET_phi,MET_etTotal,MHT_etTotal,MHT_et,MHT_phi;

   std::map<std::string, std::vector<float>* > variable_map;
   std::map<std::string, std::vector<std::vector<float>>* > variable_2d_map;
   std::map<std::string, unsigned int*> nCol_map;
   std::map<std::string, float*> variable_scalar_map;


 private:
   TTree *mytree;


};

#endif
