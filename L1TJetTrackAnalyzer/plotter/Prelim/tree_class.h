//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb 10 22:49:56 2021 by ROOT version 6.20/07
// from TChain L1TrackNtuple/Events/
//////////////////////////////////////////////////////////

#ifndef tree_class_h
#define tree_class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class tree_class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *FastJetExt_eta;
   vector<float>   *FastJetExt_matchedToGenIdx;
   vector<float>   *FastJetExt_nDispTracks;
   vector<float>   *FastJetExt_nL1Trk;
   vector<float>   *FastJetExt_nTightDispTracks;
   vector<float>   *FastJetExt_nTightTracks;
   vector<float>   *FastJetExt_nTracks;
   vector<float>   *FastJetExt_phi;
   vector<float>   *FastJetExt_pt;
   vector<float>   *FastJet_eta;
   vector<float>   *FastJet_matchedToGenIdx;
   vector<float>   *FastJet_nDispTracks;
   vector<float>   *FastJet_nL1Trk;
   vector<float>   *FastJet_nTightDispTracks;
   vector<float>   *FastJet_nTightTracks;
   vector<float>   *FastJet_nTracks;
   vector<float>   *FastJet_phi;
   vector<float>   *FastJet_pt;
   vector<float>   *GenJet_chargedEmE;
   vector<float>   *GenJet_chargedHadronE;
   vector<float>   *GenJet_eta;
   vector<float>   *GenJet_matchedToFastJetIdx;
   vector<float>   *GenJet_matchedToTrackJetIdx;
   vector<float>   *GenJet_muonE;
   vector<float>   *GenJet_neutralEmE;
   vector<float>   *GenJet_neutralHadronE;
   vector<float>   *GenJet_phi;
   vector<float>   *GenJet_pt;
   vector<float>   *PV_sum;
   vector<float>   *PV_z0;
   vector<float>   *TrackExt_chi2;
   vector<float>   *TrackExt_chi2xy;
   vector<float>   *TrackExt_chi2z;
   vector<float>   *TrackExt_d0;
   vector<float>   *TrackExt_eta;
   vector<float>   *TrackExt_gen_d0;
   vector<float>   *TrackExt_gen_dxy;
   vector<float>   *TrackExt_gen_eta;
   vector<float>   *TrackExt_gen_pdgId;
   vector<float>   *TrackExt_gen_phi;
   vector<float>   *TrackExt_gen_pt;
   vector<float>   *TrackExt_gen_x0;
   vector<float>   *TrackExt_gen_y0;
   vector<float>   *TrackExt_gen_z0;
   vector<float>   *TrackExt_isCombinatoricMC;
   vector<float>   *TrackExt_isGenuineMC;
   vector<float>   *TrackExt_isLooseGenuineMC;
   vector<float>   *TrackExt_isUnknownMC;
   vector<float>   *TrackExt_nFitPars;
   vector<float>   *TrackExt_phi;
   vector<float>   *TrackExt_pt;
   vector<float>   *TrackExt_stubConsistency;
   vector<float>   *TrackExt_x0;
   vector<float>   *TrackExt_y0;
   vector<float>   *TrackExt_z0;
   vector<float>   *TrackJetExt_eta;
   vector<float>   *TrackJetExt_matchedToGenIdx;
   vector<float>   *TrackJetExt_nDispTracks;
   vector<float>   *TrackJetExt_nL1Trk;
   vector<float>   *TrackJetExt_nTightDispTracks;
   vector<float>   *TrackJetExt_nTightTracks;
   vector<float>   *TrackJetExt_nTracks;
   vector<float>   *TrackJetExt_phi;
   vector<float>   *TrackJetExt_pt;
   vector<float>   *TrackJet_eta;
   vector<float>   *TrackJet_matchedToGenIdx;
   vector<float>   *TrackJet_nDispTracks;
   vector<float>   *TrackJet_nL1Trk;
   vector<float>   *TrackJet_nTightDispTracks;
   vector<float>   *TrackJet_nTightTracks;
   vector<float>   *TrackJet_nTracks;
   vector<float>   *TrackJet_phi;
   vector<float>   *TrackJet_pt;
   vector<float>   *Track_chi2;
   vector<float>   *Track_chi2xy;
   vector<float>   *Track_chi2z;
   vector<float>   *Track_d0;
   vector<float>   *Track_eta;
   vector<float>   *Track_gen_d0;
   vector<float>   *Track_gen_dxy;
   vector<float>   *Track_gen_eta;
   vector<float>   *Track_gen_pdgId;
   vector<float>   *Track_gen_phi;
   vector<float>   *Track_gen_pt;
   vector<float>   *Track_gen_x0;
   vector<float>   *Track_gen_y0;
   vector<float>   *Track_gen_z0;
   vector<float>   *Track_isCombinatoricMC;
   vector<float>   *Track_isGenuineMC;
   vector<float>   *Track_isLooseGenuineMC;
   vector<float>   *Track_isUnknownMC;
   vector<float>   *Track_nFitPars;
   vector<float>   *Track_phi;
   vector<float>   *Track_pt;
   vector<float>   *Track_stubConsistency;
   vector<float>   *Track_x0;
   vector<float>   *Track_y0;
   vector<float>   *Track_z0;
   UInt_t          nFastJet;
   UInt_t          nFastJetExt;
   UInt_t          nGenJet;
   UInt_t          nPV;
   UInt_t          nTrack;
   UInt_t          nTrackExt;
   UInt_t          nTrackJet;
   UInt_t          nTrackJetExt;
   vector<vector<float> > *FastJetExt_L1Trk_eta;
   vector<vector<float> > *FastJetExt_L1Trk_phi;
   vector<vector<float> > *FastJetExt_L1Trk_pt;
   vector<vector<float> > *FastJet_L1Trk_eta;
   vector<vector<float> > *FastJet_L1Trk_phi;
   vector<vector<float> > *FastJet_L1Trk_pt;
   vector<vector<float> > *TrackJetExt_L1Trk_eta;
   vector<vector<float> > *TrackJetExt_L1Trk_phi;
   vector<vector<float> > *TrackJetExt_L1Trk_pt;
   vector<vector<float> > *TrackJet_L1Trk_eta;
   vector<vector<float> > *TrackJet_L1Trk_phi;
   vector<vector<float> > *TrackJet_L1Trk_pt;
   Float_t         MET_et;
   Float_t         MET_etTotal;
   Float_t         MET_phi;
   Float_t         MHT_et;
   Float_t         MHT_etTotal;
   Float_t         MHT_phi;

   // List of branches
   TBranch        *b_FastJetExt_eta;   //!
   TBranch        *b_FastJetExt_matchedToGenIdx;   //!
   TBranch        *b_FastJetExt_nDispTracks;   //!
   TBranch        *b_FastJetExt_nL1Trk;   //!
   TBranch        *b_FastJetExt_nTightDispTracks;   //!
   TBranch        *b_FastJetExt_nTightTracks;   //!
   TBranch        *b_FastJetExt_nTracks;   //!
   TBranch        *b_FastJetExt_phi;   //!
   TBranch        *b_FastJetExt_pt;   //!
   TBranch        *b_FastJet_eta;   //!
   TBranch        *b_FastJet_matchedToGenIdx;   //!
   TBranch        *b_FastJet_nDispTracks;   //!
   TBranch        *b_FastJet_nL1Trk;   //!
   TBranch        *b_FastJet_nTightDispTracks;   //!
   TBranch        *b_FastJet_nTightTracks;   //!
   TBranch        *b_FastJet_nTracks;   //!
   TBranch        *b_FastJet_phi;   //!
   TBranch        *b_FastJet_pt;   //!
   TBranch        *b_GenJet_chargedEmE;   //!
   TBranch        *b_GenJet_chargedHadronE;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_matchedToFastJetIdx;   //!
   TBranch        *b_GenJet_matchedToTrackJetIdx;   //!
   TBranch        *b_GenJet_muonE;   //!
   TBranch        *b_GenJet_neutralEmE;   //!
   TBranch        *b_GenJet_neutralHadronE;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_pt;   //!
   TBranch        *b_PV_sum;   //!
   TBranch        *b_PV_z0;   //!
   TBranch        *b_TrackExt_chi2;   //!
   TBranch        *b_TrackExt_chi2xy;   //!
   TBranch        *b_TrackExt_chi2z;   //!
   TBranch        *b_TrackExt_d0;   //!
   TBranch        *b_TrackExt_eta;   //!
   TBranch        *b_TrackExt_gen_d0;   //!
   TBranch        *b_TrackExt_gen_dxy;   //!
   TBranch        *b_TrackExt_gen_eta;   //!
   TBranch        *b_TrackExt_gen_pdgId;   //!
   TBranch        *b_TrackExt_gen_phi;   //!
   TBranch        *b_TrackExt_gen_pt;   //!
   TBranch        *b_TrackExt_gen_x0;   //!
   TBranch        *b_TrackExt_gen_y0;   //!
   TBranch        *b_TrackExt_gen_z0;   //!
   TBranch        *b_TrackExt_isCombinatoricMC;   //!
   TBranch        *b_TrackExt_isGenuineMC;   //!
   TBranch        *b_TrackExt_isLooseGenuineMC;   //!
   TBranch        *b_TrackExt_isUnknownMC;   //!
   TBranch        *b_TrackExt_nFitPars;   //!
   TBranch        *b_TrackExt_phi;   //!
   TBranch        *b_TrackExt_pt;   //!
   TBranch        *b_TrackExt_stubConsistency;   //!
   TBranch        *b_TrackExt_x0;   //!
   TBranch        *b_TrackExt_y0;   //!
   TBranch        *b_TrackExt_z0;   //!
   TBranch        *b_TrackJetExt_eta;   //!
   TBranch        *b_TrackJetExt_matchedToGenIdx;   //!
   TBranch        *b_TrackJetExt_nDispTracks;   //!
   TBranch        *b_TrackJetExt_nL1Trk;   //!
   TBranch        *b_TrackJetExt_nTightDispTracks;   //!
   TBranch        *b_TrackJetExt_nTightTracks;   //!
   TBranch        *b_TrackJetExt_nTracks;   //!
   TBranch        *b_TrackJetExt_phi;   //!
   TBranch        *b_TrackJetExt_pt;   //!
   TBranch        *b_TrackJet_eta;   //!
   TBranch        *b_TrackJet_matchedToGenIdx;   //!
   TBranch        *b_TrackJet_nDispTracks;   //!
   TBranch        *b_TrackJet_nL1Trk;   //!
   TBranch        *b_TrackJet_nTightDispTracks;   //!
   TBranch        *b_TrackJet_nTightTracks;   //!
   TBranch        *b_TrackJet_nTracks;   //!
   TBranch        *b_TrackJet_phi;   //!
   TBranch        *b_TrackJet_pt;   //!
   TBranch        *b_Track_chi2;   //!
   TBranch        *b_Track_chi2xy;   //!
   TBranch        *b_Track_chi2z;   //!
   TBranch        *b_Track_d0;   //!
   TBranch        *b_Track_eta;   //!
   TBranch        *b_Track_gen_d0;   //!
   TBranch        *b_Track_gen_dxy;   //!
   TBranch        *b_Track_gen_eta;   //!
   TBranch        *b_Track_gen_pdgId;   //!
   TBranch        *b_Track_gen_phi;   //!
   TBranch        *b_Track_gen_pt;   //!
   TBranch        *b_Track_gen_x0;   //!
   TBranch        *b_Track_gen_y0;   //!
   TBranch        *b_Track_gen_z0;   //!
   TBranch        *b_Track_isCombinatoricMC;   //!
   TBranch        *b_Track_isGenuineMC;   //!
   TBranch        *b_Track_isLooseGenuineMC;   //!
   TBranch        *b_Track_isUnknownMC;   //!
   TBranch        *b_Track_nFitPars;   //!
   TBranch        *b_Track_phi;   //!
   TBranch        *b_Track_pt;   //!
   TBranch        *b_Track_stubConsistency;   //!
   TBranch        *b_Track_x0;   //!
   TBranch        *b_Track_y0;   //!
   TBranch        *b_Track_z0;   //!
   TBranch        *b_nFastJet;   //!
   TBranch        *b_nFastJetExt;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_nTrack;   //!
   TBranch        *b_nTrackExt;   //!
   TBranch        *b_nTrackJet;   //!
   TBranch        *b_nTrackJetExt;   //!
   TBranch        *b_FastJetExt_L1Trk_eta;   //!
   TBranch        *b_FastJetExt_L1Trk_phi;   //!
   TBranch        *b_FastJetExt_L1Trk_pt;   //!
   TBranch        *b_FastJet_L1Trk_eta;   //!
   TBranch        *b_FastJet_L1Trk_phi;   //!
   TBranch        *b_FastJet_L1Trk_pt;   //!
   TBranch        *b_TrackJetExt_L1Trk_eta;   //!
   TBranch        *b_TrackJetExt_L1Trk_phi;   //!
   TBranch        *b_TrackJetExt_L1Trk_pt;   //!
   TBranch        *b_TrackJet_L1Trk_eta;   //!
   TBranch        *b_TrackJet_L1Trk_phi;   //!
   TBranch        *b_TrackJet_L1Trk_pt;   //!
   TBranch        *b_MET_et;   //!
   TBranch        *b_MET_etTotal;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_MHT_et;   //!
   TBranch        *b_MHT_etTotal;   //!
   TBranch        *b_MHT_phi;   //!

   tree_class(TTree *tree=0);
   virtual ~tree_class();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

tree_class::tree_class(TTree *tree) : fChain(0) 
{
   Init(tree);
}

tree_class::~tree_class()
{
   if (!fChain) return;
}

Int_t tree_class::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t tree_class::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void tree_class::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   FastJetExt_eta = 0;
   FastJetExt_matchedToGenIdx = 0;
   FastJetExt_nDispTracks = 0;
   FastJetExt_nL1Trk = 0;
   FastJetExt_nTightDispTracks = 0;
   FastJetExt_nTightTracks = 0;
   FastJetExt_nTracks = 0;
   FastJetExt_phi = 0;
   FastJetExt_pt = 0;
   FastJet_eta = 0;
   FastJet_matchedToGenIdx = 0;
   FastJet_nDispTracks = 0;
   FastJet_nL1Trk = 0;
   FastJet_nTightDispTracks = 0;
   FastJet_nTightTracks = 0;
   FastJet_nTracks = 0;
   FastJet_phi = 0;
   FastJet_pt = 0;
   GenJet_chargedEmE = 0;
   GenJet_chargedHadronE = 0;
   GenJet_eta = 0;
   GenJet_matchedToFastJetIdx = 0;
   GenJet_matchedToTrackJetIdx = 0;
   GenJet_muonE = 0;
   GenJet_neutralEmE = 0;
   GenJet_neutralHadronE = 0;
   GenJet_phi = 0;
   GenJet_pt = 0;
   PV_sum = 0;
   PV_z0 = 0;
   TrackExt_chi2 = 0;
   TrackExt_chi2xy = 0;
   TrackExt_chi2z = 0;
   TrackExt_d0 = 0;
   TrackExt_eta = 0;
   TrackExt_gen_d0 = 0;
   TrackExt_gen_dxy = 0;
   TrackExt_gen_eta = 0;
   TrackExt_gen_pdgId = 0;
   TrackExt_gen_phi = 0;
   TrackExt_gen_pt = 0;
   TrackExt_gen_x0 = 0;
   TrackExt_gen_y0 = 0;
   TrackExt_gen_z0 = 0;
   TrackExt_isCombinatoricMC = 0;
   TrackExt_isGenuineMC = 0;
   TrackExt_isLooseGenuineMC = 0;
   TrackExt_isUnknownMC = 0;
   TrackExt_nFitPars = 0;
   TrackExt_phi = 0;
   TrackExt_pt = 0;
   TrackExt_stubConsistency = 0;
   TrackExt_x0 = 0;
   TrackExt_y0 = 0;
   TrackExt_z0 = 0;
   TrackJetExt_eta = 0;
   TrackJetExt_matchedToGenIdx = 0;
   TrackJetExt_nDispTracks = 0;
   TrackJetExt_nL1Trk = 0;
   TrackJetExt_nTightDispTracks = 0;
   TrackJetExt_nTightTracks = 0;
   TrackJetExt_nTracks = 0;
   TrackJetExt_phi = 0;
   TrackJetExt_pt = 0;
   TrackJet_eta = 0;
   TrackJet_matchedToGenIdx = 0;
   TrackJet_nDispTracks = 0;
   TrackJet_nL1Trk = 0;
   TrackJet_nTightDispTracks = 0;
   TrackJet_nTightTracks = 0;
   TrackJet_nTracks = 0;
   TrackJet_phi = 0;
   TrackJet_pt = 0;
   Track_chi2 = 0;
   Track_chi2xy = 0;
   Track_chi2z = 0;
   Track_d0 = 0;
   Track_eta = 0;
   Track_gen_d0 = 0;
   Track_gen_dxy = 0;
   Track_gen_eta = 0;
   Track_gen_pdgId = 0;
   Track_gen_phi = 0;
   Track_gen_pt = 0;
   Track_gen_x0 = 0;
   Track_gen_y0 = 0;
   Track_gen_z0 = 0;
   Track_isCombinatoricMC = 0;
   Track_isGenuineMC = 0;
   Track_isLooseGenuineMC = 0;
   Track_isUnknownMC = 0;
   Track_nFitPars = 0;
   Track_phi = 0;
   Track_pt = 0;
   Track_stubConsistency = 0;
   Track_x0 = 0;
   Track_y0 = 0;
   Track_z0 = 0;
   FastJetExt_L1Trk_eta = 0;
   FastJetExt_L1Trk_phi = 0;
   FastJetExt_L1Trk_pt = 0;
   FastJet_L1Trk_eta = 0;
   FastJet_L1Trk_phi = 0;
   FastJet_L1Trk_pt = 0;
   TrackJetExt_L1Trk_eta = 0;
   TrackJetExt_L1Trk_phi = 0;
   TrackJetExt_L1Trk_pt = 0;
   TrackJet_L1Trk_eta = 0;
   TrackJet_L1Trk_phi = 0;
   TrackJet_L1Trk_pt = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("FastJetExt_eta", &FastJetExt_eta, &b_FastJetExt_eta);
   fChain->SetBranchAddress("FastJetExt_matchedToGenIdx", &FastJetExt_matchedToGenIdx, &b_FastJetExt_matchedToGenIdx);
   fChain->SetBranchAddress("FastJetExt_nDispTracks", &FastJetExt_nDispTracks, &b_FastJetExt_nDispTracks);
   fChain->SetBranchAddress("FastJetExt_nL1Trk", &FastJetExt_nL1Trk, &b_FastJetExt_nL1Trk);
   fChain->SetBranchAddress("FastJetExt_nTightDispTracks", &FastJetExt_nTightDispTracks, &b_FastJetExt_nTightDispTracks);
   fChain->SetBranchAddress("FastJetExt_nTightTracks", &FastJetExt_nTightTracks, &b_FastJetExt_nTightTracks);
   fChain->SetBranchAddress("FastJetExt_nTracks", &FastJetExt_nTracks, &b_FastJetExt_nTracks);
   fChain->SetBranchAddress("FastJetExt_phi", &FastJetExt_phi, &b_FastJetExt_phi);
   fChain->SetBranchAddress("FastJetExt_pt", &FastJetExt_pt, &b_FastJetExt_pt);
   fChain->SetBranchAddress("FastJet_eta", &FastJet_eta, &b_FastJet_eta);
   fChain->SetBranchAddress("FastJet_matchedToGenIdx", &FastJet_matchedToGenIdx, &b_FastJet_matchedToGenIdx);
   fChain->SetBranchAddress("FastJet_nDispTracks", &FastJet_nDispTracks, &b_FastJet_nDispTracks);
   fChain->SetBranchAddress("FastJet_nL1Trk", &FastJet_nL1Trk, &b_FastJet_nL1Trk);
   fChain->SetBranchAddress("FastJet_nTightDispTracks", &FastJet_nTightDispTracks, &b_FastJet_nTightDispTracks);
   fChain->SetBranchAddress("FastJet_nTightTracks", &FastJet_nTightTracks, &b_FastJet_nTightTracks);
   fChain->SetBranchAddress("FastJet_nTracks", &FastJet_nTracks, &b_FastJet_nTracks);
   fChain->SetBranchAddress("FastJet_phi", &FastJet_phi, &b_FastJet_phi);
   fChain->SetBranchAddress("FastJet_pt", &FastJet_pt, &b_FastJet_pt);
   fChain->SetBranchAddress("GenJet_chargedEmE", &GenJet_chargedEmE, &b_GenJet_chargedEmE);
   fChain->SetBranchAddress("GenJet_chargedHadronE", &GenJet_chargedHadronE, &b_GenJet_chargedHadronE);
   fChain->SetBranchAddress("GenJet_eta", &GenJet_eta, &b_GenJet_eta);
   fChain->SetBranchAddress("GenJet_matchedToFastJetIdx", &GenJet_matchedToFastJetIdx, &b_GenJet_matchedToFastJetIdx);
   fChain->SetBranchAddress("GenJet_matchedToTrackJetIdx", &GenJet_matchedToTrackJetIdx, &b_GenJet_matchedToTrackJetIdx);
   fChain->SetBranchAddress("GenJet_muonE", &GenJet_muonE, &b_GenJet_muonE);
   fChain->SetBranchAddress("GenJet_neutralEmE", &GenJet_neutralEmE, &b_GenJet_neutralEmE);
   fChain->SetBranchAddress("GenJet_neutralHadronE", &GenJet_neutralHadronE, &b_GenJet_neutralHadronE);
   fChain->SetBranchAddress("GenJet_phi", &GenJet_phi, &b_GenJet_phi);
   fChain->SetBranchAddress("GenJet_pt", &GenJet_pt, &b_GenJet_pt);
   fChain->SetBranchAddress("PV_sum", &PV_sum, &b_PV_sum);
   fChain->SetBranchAddress("PV_z0", &PV_z0, &b_PV_z0);
   fChain->SetBranchAddress("TrackExt_chi2", &TrackExt_chi2, &b_TrackExt_chi2);
   fChain->SetBranchAddress("TrackExt_chi2xy", &TrackExt_chi2xy, &b_TrackExt_chi2xy);
   fChain->SetBranchAddress("TrackExt_chi2z", &TrackExt_chi2z, &b_TrackExt_chi2z);
   fChain->SetBranchAddress("TrackExt_d0", &TrackExt_d0, &b_TrackExt_d0);
   fChain->SetBranchAddress("TrackExt_eta", &TrackExt_eta, &b_TrackExt_eta);
   fChain->SetBranchAddress("TrackExt_gen_d0", &TrackExt_gen_d0, &b_TrackExt_gen_d0);
   fChain->SetBranchAddress("TrackExt_gen_dxy", &TrackExt_gen_dxy, &b_TrackExt_gen_dxy);
   fChain->SetBranchAddress("TrackExt_gen_eta", &TrackExt_gen_eta, &b_TrackExt_gen_eta);
   fChain->SetBranchAddress("TrackExt_gen_pdgId", &TrackExt_gen_pdgId, &b_TrackExt_gen_pdgId);
   fChain->SetBranchAddress("TrackExt_gen_phi", &TrackExt_gen_phi, &b_TrackExt_gen_phi);
   fChain->SetBranchAddress("TrackExt_gen_pt", &TrackExt_gen_pt, &b_TrackExt_gen_pt);
   fChain->SetBranchAddress("TrackExt_gen_x0", &TrackExt_gen_x0, &b_TrackExt_gen_x0);
   fChain->SetBranchAddress("TrackExt_gen_y0", &TrackExt_gen_y0, &b_TrackExt_gen_y0);
   fChain->SetBranchAddress("TrackExt_gen_z0", &TrackExt_gen_z0, &b_TrackExt_gen_z0);
   fChain->SetBranchAddress("TrackExt_isCombinatoricMC", &TrackExt_isCombinatoricMC, &b_TrackExt_isCombinatoricMC);
   fChain->SetBranchAddress("TrackExt_isGenuineMC", &TrackExt_isGenuineMC, &b_TrackExt_isGenuineMC);
   fChain->SetBranchAddress("TrackExt_isLooseGenuineMC", &TrackExt_isLooseGenuineMC, &b_TrackExt_isLooseGenuineMC);
   fChain->SetBranchAddress("TrackExt_isUnknownMC", &TrackExt_isUnknownMC, &b_TrackExt_isUnknownMC);
   fChain->SetBranchAddress("TrackExt_nFitPars", &TrackExt_nFitPars, &b_TrackExt_nFitPars);
   fChain->SetBranchAddress("TrackExt_phi", &TrackExt_phi, &b_TrackExt_phi);
   fChain->SetBranchAddress("TrackExt_pt", &TrackExt_pt, &b_TrackExt_pt);
   fChain->SetBranchAddress("TrackExt_stubConsistency", &TrackExt_stubConsistency, &b_TrackExt_stubConsistency);
   fChain->SetBranchAddress("TrackExt_x0", &TrackExt_x0, &b_TrackExt_x0);
   fChain->SetBranchAddress("TrackExt_y0", &TrackExt_y0, &b_TrackExt_y0);
   fChain->SetBranchAddress("TrackExt_z0", &TrackExt_z0, &b_TrackExt_z0);
   fChain->SetBranchAddress("TrackJetExt_eta", &TrackJetExt_eta, &b_TrackJetExt_eta);
   fChain->SetBranchAddress("TrackJetExt_matchedToGenIdx", &TrackJetExt_matchedToGenIdx, &b_TrackJetExt_matchedToGenIdx);
   fChain->SetBranchAddress("TrackJetExt_nDispTracks", &TrackJetExt_nDispTracks, &b_TrackJetExt_nDispTracks);
   fChain->SetBranchAddress("TrackJetExt_nL1Trk", &TrackJetExt_nL1Trk, &b_TrackJetExt_nL1Trk);
   fChain->SetBranchAddress("TrackJetExt_nTightDispTracks", &TrackJetExt_nTightDispTracks, &b_TrackJetExt_nTightDispTracks);
   fChain->SetBranchAddress("TrackJetExt_nTightTracks", &TrackJetExt_nTightTracks, &b_TrackJetExt_nTightTracks);
   fChain->SetBranchAddress("TrackJetExt_nTracks", &TrackJetExt_nTracks, &b_TrackJetExt_nTracks);
   fChain->SetBranchAddress("TrackJetExt_phi", &TrackJetExt_phi, &b_TrackJetExt_phi);
   fChain->SetBranchAddress("TrackJetExt_pt", &TrackJetExt_pt, &b_TrackJetExt_pt);
   fChain->SetBranchAddress("TrackJet_eta", &TrackJet_eta, &b_TrackJet_eta);
   fChain->SetBranchAddress("TrackJet_matchedToGenIdx", &TrackJet_matchedToGenIdx, &b_TrackJet_matchedToGenIdx);
   fChain->SetBranchAddress("TrackJet_nDispTracks", &TrackJet_nDispTracks, &b_TrackJet_nDispTracks);
   fChain->SetBranchAddress("TrackJet_nL1Trk", &TrackJet_nL1Trk, &b_TrackJet_nL1Trk);
   fChain->SetBranchAddress("TrackJet_nTightDispTracks", &TrackJet_nTightDispTracks, &b_TrackJet_nTightDispTracks);
   fChain->SetBranchAddress("TrackJet_nTightTracks", &TrackJet_nTightTracks, &b_TrackJet_nTightTracks);
   fChain->SetBranchAddress("TrackJet_nTracks", &TrackJet_nTracks, &b_TrackJet_nTracks);
   fChain->SetBranchAddress("TrackJet_phi", &TrackJet_phi, &b_TrackJet_phi);
   fChain->SetBranchAddress("TrackJet_pt", &TrackJet_pt, &b_TrackJet_pt);
   fChain->SetBranchAddress("Track_chi2", &Track_chi2, &b_Track_chi2);
   fChain->SetBranchAddress("Track_chi2xy", &Track_chi2xy, &b_Track_chi2xy);
   fChain->SetBranchAddress("Track_chi2z", &Track_chi2z, &b_Track_chi2z);
   fChain->SetBranchAddress("Track_d0", &Track_d0, &b_Track_d0);
   fChain->SetBranchAddress("Track_eta", &Track_eta, &b_Track_eta);
   fChain->SetBranchAddress("Track_gen_d0", &Track_gen_d0, &b_Track_gen_d0);
   fChain->SetBranchAddress("Track_gen_dxy", &Track_gen_dxy, &b_Track_gen_dxy);
   fChain->SetBranchAddress("Track_gen_eta", &Track_gen_eta, &b_Track_gen_eta);
   fChain->SetBranchAddress("Track_gen_pdgId", &Track_gen_pdgId, &b_Track_gen_pdgId);
   fChain->SetBranchAddress("Track_gen_phi", &Track_gen_phi, &b_Track_gen_phi);
   fChain->SetBranchAddress("Track_gen_pt", &Track_gen_pt, &b_Track_gen_pt);
   fChain->SetBranchAddress("Track_gen_x0", &Track_gen_x0, &b_Track_gen_x0);
   fChain->SetBranchAddress("Track_gen_y0", &Track_gen_y0, &b_Track_gen_y0);
   fChain->SetBranchAddress("Track_gen_z0", &Track_gen_z0, &b_Track_gen_z0);
   fChain->SetBranchAddress("Track_isCombinatoricMC", &Track_isCombinatoricMC, &b_Track_isCombinatoricMC);
   fChain->SetBranchAddress("Track_isGenuineMC", &Track_isGenuineMC, &b_Track_isGenuineMC);
   fChain->SetBranchAddress("Track_isLooseGenuineMC", &Track_isLooseGenuineMC, &b_Track_isLooseGenuineMC);
   fChain->SetBranchAddress("Track_isUnknownMC", &Track_isUnknownMC, &b_Track_isUnknownMC);
   fChain->SetBranchAddress("Track_nFitPars", &Track_nFitPars, &b_Track_nFitPars);
   fChain->SetBranchAddress("Track_phi", &Track_phi, &b_Track_phi);
   fChain->SetBranchAddress("Track_pt", &Track_pt, &b_Track_pt);
   fChain->SetBranchAddress("Track_stubConsistency", &Track_stubConsistency, &b_Track_stubConsistency);
   fChain->SetBranchAddress("Track_x0", &Track_x0, &b_Track_x0);
   fChain->SetBranchAddress("Track_y0", &Track_y0, &b_Track_y0);
   fChain->SetBranchAddress("Track_z0", &Track_z0, &b_Track_z0);
   fChain->SetBranchAddress("nFastJet", &nFastJet, &b_nFastJet);
   fChain->SetBranchAddress("nFastJetExt", &nFastJetExt, &b_nFastJetExt);
   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("nTrack", &nTrack, &b_nTrack);
   fChain->SetBranchAddress("nTrackExt", &nTrackExt, &b_nTrackExt);
   fChain->SetBranchAddress("nTrackJet", &nTrackJet, &b_nTrackJet);
   fChain->SetBranchAddress("nTrackJetExt", &nTrackJetExt, &b_nTrackJetExt);
   fChain->SetBranchAddress("FastJetExt_L1Trk_eta", &FastJetExt_L1Trk_eta, &b_FastJetExt_L1Trk_eta);
   fChain->SetBranchAddress("FastJetExt_L1Trk_phi", &FastJetExt_L1Trk_phi, &b_FastJetExt_L1Trk_phi);
   fChain->SetBranchAddress("FastJetExt_L1Trk_pt", &FastJetExt_L1Trk_pt, &b_FastJetExt_L1Trk_pt);
   fChain->SetBranchAddress("FastJet_L1Trk_eta", &FastJet_L1Trk_eta, &b_FastJet_L1Trk_eta);
   fChain->SetBranchAddress("FastJet_L1Trk_phi", &FastJet_L1Trk_phi, &b_FastJet_L1Trk_phi);
   fChain->SetBranchAddress("FastJet_L1Trk_pt", &FastJet_L1Trk_pt, &b_FastJet_L1Trk_pt);
   fChain->SetBranchAddress("TrackJetExt_L1Trk_eta", &TrackJetExt_L1Trk_eta, &b_TrackJetExt_L1Trk_eta);
   fChain->SetBranchAddress("TrackJetExt_L1Trk_phi", &TrackJetExt_L1Trk_phi, &b_TrackJetExt_L1Trk_phi);
   fChain->SetBranchAddress("TrackJetExt_L1Trk_pt", &TrackJetExt_L1Trk_pt, &b_TrackJetExt_L1Trk_pt);
   fChain->SetBranchAddress("TrackJet_L1Trk_eta", &TrackJet_L1Trk_eta, &b_TrackJet_L1Trk_eta);
   fChain->SetBranchAddress("TrackJet_L1Trk_phi", &TrackJet_L1Trk_phi, &b_TrackJet_L1Trk_phi);
   fChain->SetBranchAddress("TrackJet_L1Trk_pt", &TrackJet_L1Trk_pt, &b_TrackJet_L1Trk_pt);
   fChain->SetBranchAddress("MET_et", &MET_et, &b_MET_et);
   fChain->SetBranchAddress("MET_etTotal", &MET_etTotal, &b_MET_etTotal);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("MHT_et", &MHT_et, &b_MHT_et);
   fChain->SetBranchAddress("MHT_etTotal", &MHT_etTotal, &b_MHT_etTotal);
   fChain->SetBranchAddress("MHT_phi", &MHT_phi, &b_MHT_phi);
   Notify();
}

Bool_t tree_class::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void tree_class::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t tree_class::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef tree_class_cxx
