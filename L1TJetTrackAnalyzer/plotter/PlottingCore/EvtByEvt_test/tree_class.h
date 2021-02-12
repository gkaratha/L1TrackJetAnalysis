//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 20 22:02:26 2021 by ROOT version 6.20/07
// from TTree eventTree/Event tree
// found on file: /eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Jan20/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU0/210120_104033/0000/L1Jets_2021Jan20_117.root
//////////////////////////////////////////////////////////

#ifndef tree_class_h
#define tree_class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class tree_class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *trk_pt;
   vector<float>   *trk_eta;
   vector<float>   *trk_phi;
   vector<float>   *trk_d0;
   vector<float>   *trk_z0;
   vector<float>   *trk_chi2;
   vector<float>   *trk_chi2dof;
   vector<float>   *trk_chi2rphi;
   vector<float>   *trk_chi2rz;
   vector<float>   *trk_bendchi2;
   vector<int>     *trk_nstub;
   vector<int>     *trk_lhits;
   vector<int>     *trk_dhits;
   vector<int>     *trk_seed;
   vector<int>     *trk_hitpattern;
   vector<unsigned int> *trk_phiSector;
   vector<int>     *trk_genuine;
   vector<int>     *trk_loose;
   vector<int>     *trk_unknown;
   vector<int>     *trk_combinatoric;
   vector<int>     *trk_fake;
   vector<int>     *trk_matchtp_pdgid;
   vector<float>   *trk_matchtp_pt;
   vector<float>   *trk_matchtp_eta;
   vector<float>   *trk_matchtp_phi;
   vector<float>   *trk_matchtp_z0;
   vector<float>   *trk_matchtp_dxy;
   vector<float>   *tp_pt;
   vector<float>   *tp_eta;
   vector<float>   *tp_phi;
   vector<float>   *tp_dxy;
   vector<float>   *tp_d0;
   vector<float>   *tp_z0;
   vector<float>   *tp_d0_prod;
   vector<float>   *tp_z0_prod;
   vector<int>     *tp_pdgid;
   vector<int>     *tp_nmatch;
   vector<int>     *tp_nstub;
   vector<int>     *tp_eventid;
   vector<int>     *tp_charge;
   vector<float>   *matchtrk_pt;
   vector<float>   *matchtrk_eta;
   vector<float>   *matchtrk_phi;
   vector<float>   *matchtrk_z0;
   vector<float>   *matchtrk_d0;
   vector<float>   *matchtrk_chi2;
   vector<float>   *matchtrk_chi2dof;
   vector<float>   *matchtrk_chi2rphi;
   vector<float>   *matchtrk_chi2rz;
   vector<float>   *matchtrk_bendchi2;
   vector<int>     *matchtrk_nstub;
   vector<int>     *matchtrk_lhits;
   vector<int>     *matchtrk_dhits;
   vector<int>     *matchtrk_seed;
   vector<int>     *matchtrk_hitpattern;
   vector<float>   *genjet_eta;
   vector<float>   *genjet_phi;
   vector<float>   *genjet_pt;
   vector<float>   *pv_L1reco_z0;
   vector<float>   *pv_L1reco_sum;
   vector<int>     *MC_lep;
   vector<float>   *pv_MC;
   vector<float>   *ltrkjet_eta;
   vector<float>   *ltrkjet_vz;
   vector<float>   *ltrkjet_p;
   vector<float>   *ltrkjet_pt;
   vector<float>   *ltrkjet_phi;
   vector<int>     *ltrkjet_ntracks;
   vector<int>     *ltrkjet_nDisplaced;
   vector<int>     *ltrkjet_nTight;
   vector<int>     *ltrkjet_nTightDisplaced;
   vector<float>   *trkjet_eta;
   vector<float>   *trkjet_vz;
   vector<float>   *trkjet_p;
   vector<float>   *trkjet_pt;
   vector<float>   *trkjet_phi;
   vector<int>     *trkjet_ntracks;
   vector<float>   *trkjet_truetp_sumpt;
   Float_t         trueMET;
   Float_t         trkMET;
   Float_t         trkMHT;
   Float_t         trkHT;

   // List of branches
   TBranch        *b_trk_pt;   //!
   TBranch        *b_trk_eta;   //!
   TBranch        *b_trk_phi;   //!
   TBranch        *b_trk_d0;   //!
   TBranch        *b_trk_z0;   //!
   TBranch        *b_trk_chi2;   //!
   TBranch        *b_trk_chi2dof;   //!
   TBranch        *b_trk_chi2rphi;   //!
   TBranch        *b_trk_chi2rz;   //!
   TBranch        *b_trk_bendchi2;   //!
   TBranch        *b_trk_nstub;   //!
   TBranch        *b_trk_lhits;   //!
   TBranch        *b_trk_dhits;   //!
   TBranch        *b_trk_seed;   //!
   TBranch        *b_trk_hitpattern;   //!
   TBranch        *b_trk_phiSector;   //!
   TBranch        *b_trk_genuine;   //!
   TBranch        *b_trk_loose;   //!
   TBranch        *b_trk_unknown;   //!
   TBranch        *b_trk_combinatoric;   //!
   TBranch        *b_trk_fake;   //!
   TBranch        *b_trk_matchtp_pdgid;   //!
   TBranch        *b_trk_matchtp_pt;   //!
   TBranch        *b_trk_matchtp_eta;   //!
   TBranch        *b_trk_matchtp_phi;   //!
   TBranch        *b_trk_matchtp_z0;   //!
   TBranch        *b_trk_matchtp_dxy;   //!
   TBranch        *b_tp_pt;   //!
   TBranch        *b_tp_eta;   //!
   TBranch        *b_tp_phi;   //!
   TBranch        *b_tp_dxy;   //!
   TBranch        *b_tp_d0;   //!
   TBranch        *b_tp_z0;   //!
   TBranch        *b_tp_d0_prod;   //!
   TBranch        *b_tp_z0_prod;   //!
   TBranch        *b_tp_pdgid;   //!
   TBranch        *b_tp_nmatch;   //!
   TBranch        *b_tp_nstub;   //!
   TBranch        *b_tp_eventid;   //!
   TBranch        *b_tp_charge;   //!
   TBranch        *b_matchtrk_pt;   //!
   TBranch        *b_matchtrk_eta;   //!
   TBranch        *b_matchtrk_phi;   //!
   TBranch        *b_matchtrk_z0;   //!
   TBranch        *b_matchtrk_d0;   //!
   TBranch        *b_matchtrk_chi2;   //!
   TBranch        *b_matchtrk_chi2dof;   //!
   TBranch        *b_matchtrk_chi2rphi;   //!
   TBranch        *b_matchtrk_chi2rz;   //!
   TBranch        *b_matchtrk_bendchi2;   //!
   TBranch        *b_matchtrk_nstub;   //!
   TBranch        *b_matchtrk_lhits;   //!
   TBranch        *b_matchtrk_dhits;   //!
   TBranch        *b_matchtrk_seed;   //!
   TBranch        *b_matchtrk_hitpattern;   //!
   TBranch        *b_genjet_eta;   //!
   TBranch        *b_genjet_phi;   //!
   TBranch        *b_genjet_pt;   //!
   TBranch        *b_pv_L1reco_z0;   //!
   TBranch        *b_pv_L1reco_sum;   //!
   TBranch        *b_MC_lep;   //!
   TBranch        *b_pv_MC;   //!
   TBranch        *b_2ltrkjet_eta;   //!
   TBranch        *b_2ltrkjet_vz;   //!
   TBranch        *b_2ltrkjet_p;   //!
   TBranch        *b_2ltrkjet_pt;   //!
   TBranch        *b_2ltrkjet_phi;   //!
   TBranch        *b_2ltrkjet_ntracks;   //!
   TBranch        *b_2ltrkjet_nDisplaced;   //!
   TBranch        *b_2ltrkjet_nTight;   //!
   TBranch        *b_2ltrkjet_nTightDisplaced;   //!
   TBranch        *b_trkjet_eta;   //!
   TBranch        *b_trkjet_vz;   //!
   TBranch        *b_trkjet_p;   //!
   TBranch        *b_trkjet_pt;   //!
   TBranch        *b_trkjet_phi;   //!
   TBranch        *b_trkjet_ntracks;   //!
   TBranch        *b_trkjet_truetp_sumpt;   //!
   TBranch        *b_trueMET;   //!
   TBranch        *b_trkMET;   //!
   TBranch        *b_trkMHT;   //!
   TBranch        *b_trkHT;   //!

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
   trk_pt = 0;
   trk_eta = 0;
   trk_phi = 0;
   trk_d0 = 0;
   trk_z0 = 0;
   trk_chi2 = 0;
   trk_chi2dof = 0;
   trk_chi2rphi = 0;
   trk_chi2rz = 0;
   trk_bendchi2 = 0;
   trk_nstub = 0;
   trk_lhits = 0;
   trk_dhits = 0;
   trk_seed = 0;
   trk_hitpattern = 0;
   trk_phiSector = 0;
   trk_genuine = 0;
   trk_loose = 0;
   trk_unknown = 0;
   trk_combinatoric = 0;
   trk_fake = 0;
   trk_matchtp_pdgid = 0;
   trk_matchtp_pt = 0;
   trk_matchtp_eta = 0;
   trk_matchtp_phi = 0;
   trk_matchtp_z0 = 0;
   trk_matchtp_dxy = 0;
   tp_pt = 0;
   tp_eta = 0;
   tp_phi = 0;
   tp_dxy = 0;
   tp_d0 = 0;
   tp_z0 = 0;
   tp_d0_prod = 0;
   tp_z0_prod = 0;
   tp_pdgid = 0;
   tp_nmatch = 0;
   tp_nstub = 0;
   tp_eventid = 0;
   tp_charge = 0;
   matchtrk_pt = 0;
   matchtrk_eta = 0;
   matchtrk_phi = 0;
   matchtrk_z0 = 0;
   matchtrk_d0 = 0;
   matchtrk_chi2 = 0;
   matchtrk_chi2dof = 0;
   matchtrk_chi2rphi = 0;
   matchtrk_chi2rz = 0;
   matchtrk_bendchi2 = 0;
   matchtrk_nstub = 0;
   matchtrk_lhits = 0;
   matchtrk_dhits = 0;
   matchtrk_seed = 0;
   matchtrk_hitpattern = 0;
   genjet_eta = 0;
   genjet_phi = 0;
   genjet_pt = 0;
   pv_L1reco_z0 = 0;
   pv_L1reco_sum = 0;
   MC_lep = 0;
   pv_MC = 0;
   ltrkjet_eta = 0;
   ltrkjet_vz = 0;
   ltrkjet_p = 0;
   ltrkjet_pt = 0;
   ltrkjet_phi = 0;
   ltrkjet_ntracks = 0;
   ltrkjet_nDisplaced = 0;
   ltrkjet_nTight = 0;
   ltrkjet_nTightDisplaced = 0;
   trkjet_eta = 0;
   trkjet_vz = 0;
   trkjet_p = 0;
   trkjet_pt = 0;
   trkjet_phi = 0;
   trkjet_ntracks = 0;
   trkjet_truetp_sumpt = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("trk_pt", &trk_pt, &b_trk_pt);
   fChain->SetBranchAddress("trk_eta", &trk_eta, &b_trk_eta);
   fChain->SetBranchAddress("trk_phi", &trk_phi, &b_trk_phi);
   fChain->SetBranchAddress("trk_d0", &trk_d0, &b_trk_d0);
   fChain->SetBranchAddress("trk_z0", &trk_z0, &b_trk_z0);
   fChain->SetBranchAddress("trk_chi2", &trk_chi2, &b_trk_chi2);
   fChain->SetBranchAddress("trk_chi2dof", &trk_chi2dof, &b_trk_chi2dof);
   fChain->SetBranchAddress("trk_chi2rphi", &trk_chi2rphi, &b_trk_chi2rphi);
   fChain->SetBranchAddress("trk_chi2rz", &trk_chi2rz, &b_trk_chi2rz);
   fChain->SetBranchAddress("trk_bendchi2", &trk_bendchi2, &b_trk_bendchi2);
   fChain->SetBranchAddress("trk_nstub", &trk_nstub, &b_trk_nstub);
   fChain->SetBranchAddress("trk_lhits", &trk_lhits, &b_trk_lhits);
   fChain->SetBranchAddress("trk_dhits", &trk_dhits, &b_trk_dhits);
   fChain->SetBranchAddress("trk_seed", &trk_seed, &b_trk_seed);
   fChain->SetBranchAddress("trk_hitpattern", &trk_hitpattern, &b_trk_hitpattern);
   fChain->SetBranchAddress("trk_phiSector", &trk_phiSector, &b_trk_phiSector);
   fChain->SetBranchAddress("trk_genuine", &trk_genuine, &b_trk_genuine);
   fChain->SetBranchAddress("trk_loose", &trk_loose, &b_trk_loose);
   fChain->SetBranchAddress("trk_unknown", &trk_unknown, &b_trk_unknown);
   fChain->SetBranchAddress("trk_combinatoric", &trk_combinatoric, &b_trk_combinatoric);
   fChain->SetBranchAddress("trk_fake", &trk_fake, &b_trk_fake);
   fChain->SetBranchAddress("trk_matchtp_pdgid", &trk_matchtp_pdgid, &b_trk_matchtp_pdgid);
   fChain->SetBranchAddress("trk_matchtp_pt", &trk_matchtp_pt, &b_trk_matchtp_pt);
   fChain->SetBranchAddress("trk_matchtp_eta", &trk_matchtp_eta, &b_trk_matchtp_eta);
   fChain->SetBranchAddress("trk_matchtp_phi", &trk_matchtp_phi, &b_trk_matchtp_phi);
   fChain->SetBranchAddress("trk_matchtp_z0", &trk_matchtp_z0, &b_trk_matchtp_z0);
   fChain->SetBranchAddress("trk_matchtp_dxy", &trk_matchtp_dxy, &b_trk_matchtp_dxy);
   fChain->SetBranchAddress("tp_pt", &tp_pt, &b_tp_pt);
   fChain->SetBranchAddress("tp_eta", &tp_eta, &b_tp_eta);
   fChain->SetBranchAddress("tp_phi", &tp_phi, &b_tp_phi);
   fChain->SetBranchAddress("tp_dxy", &tp_dxy, &b_tp_dxy);
   fChain->SetBranchAddress("tp_d0", &tp_d0, &b_tp_d0);
   fChain->SetBranchAddress("tp_z0", &tp_z0, &b_tp_z0);
   fChain->SetBranchAddress("tp_d0_prod", &tp_d0_prod, &b_tp_d0_prod);
   fChain->SetBranchAddress("tp_z0_prod", &tp_z0_prod, &b_tp_z0_prod);
   fChain->SetBranchAddress("tp_pdgid", &tp_pdgid, &b_tp_pdgid);
   fChain->SetBranchAddress("tp_nmatch", &tp_nmatch, &b_tp_nmatch);
   fChain->SetBranchAddress("tp_nstub", &tp_nstub, &b_tp_nstub);
   fChain->SetBranchAddress("tp_eventid", &tp_eventid, &b_tp_eventid);
   fChain->SetBranchAddress("tp_charge", &tp_charge, &b_tp_charge);
   fChain->SetBranchAddress("matchtrk_pt", &matchtrk_pt, &b_matchtrk_pt);
   fChain->SetBranchAddress("matchtrk_eta", &matchtrk_eta, &b_matchtrk_eta);
   fChain->SetBranchAddress("matchtrk_phi", &matchtrk_phi, &b_matchtrk_phi);
   fChain->SetBranchAddress("matchtrk_z0", &matchtrk_z0, &b_matchtrk_z0);
   fChain->SetBranchAddress("matchtrk_d0", &matchtrk_d0, &b_matchtrk_d0);
   fChain->SetBranchAddress("matchtrk_chi2", &matchtrk_chi2, &b_matchtrk_chi2);
   fChain->SetBranchAddress("matchtrk_chi2dof", &matchtrk_chi2dof, &b_matchtrk_chi2dof);
   fChain->SetBranchAddress("matchtrk_chi2rphi", &matchtrk_chi2rphi, &b_matchtrk_chi2rphi);
   fChain->SetBranchAddress("matchtrk_chi2rz", &matchtrk_chi2rz, &b_matchtrk_chi2rz);
   fChain->SetBranchAddress("matchtrk_bendchi2", &matchtrk_bendchi2, &b_matchtrk_bendchi2);
   fChain->SetBranchAddress("matchtrk_nstub", &matchtrk_nstub, &b_matchtrk_nstub);
   fChain->SetBranchAddress("matchtrk_lhits", &matchtrk_lhits, &b_matchtrk_lhits);
   fChain->SetBranchAddress("matchtrk_dhits", &matchtrk_dhits, &b_matchtrk_dhits);
   fChain->SetBranchAddress("matchtrk_seed", &matchtrk_seed, &b_matchtrk_seed);
   fChain->SetBranchAddress("matchtrk_hitpattern", &matchtrk_hitpattern, &b_matchtrk_hitpattern);
   fChain->SetBranchAddress("genjet_eta", &genjet_eta, &b_genjet_eta);
   fChain->SetBranchAddress("genjet_phi", &genjet_phi, &b_genjet_phi);
   fChain->SetBranchAddress("genjet_pt", &genjet_pt, &b_genjet_pt);
   fChain->SetBranchAddress("pv_L1reco_z0", &pv_L1reco_z0, &b_pv_L1reco_z0);
   fChain->SetBranchAddress("pv_L1reco_sum", &pv_L1reco_sum, &b_pv_L1reco_sum);
   fChain->SetBranchAddress("MC_lep", &MC_lep, &b_MC_lep);
   fChain->SetBranchAddress("pv_MC", &pv_MC, &b_pv_MC);
   fChain->SetBranchAddress("2ltrkjet_eta", &ltrkjet_eta, &b_2ltrkjet_eta);
   fChain->SetBranchAddress("2ltrkjet_vz", &ltrkjet_vz, &b_2ltrkjet_vz);
   fChain->SetBranchAddress("2ltrkjet_p", &ltrkjet_p, &b_2ltrkjet_p);
   fChain->SetBranchAddress("2ltrkjet_pt", &ltrkjet_pt, &b_2ltrkjet_pt);
   fChain->SetBranchAddress("2ltrkjet_phi", &ltrkjet_phi, &b_2ltrkjet_phi);
   fChain->SetBranchAddress("2ltrkjet_ntracks", &ltrkjet_ntracks, &b_2ltrkjet_ntracks);
   fChain->SetBranchAddress("2ltrkjet_nDisplaced", &ltrkjet_nDisplaced, &b_2ltrkjet_nDisplaced);
   fChain->SetBranchAddress("2ltrkjet_nTight", &ltrkjet_nTight, &b_2ltrkjet_nTight);
   fChain->SetBranchAddress("2ltrkjet_nTightDisplaced", &ltrkjet_nTightDisplaced, &b_2ltrkjet_nTightDisplaced);
   fChain->SetBranchAddress("trkjet_eta", &trkjet_eta, &b_trkjet_eta);
   fChain->SetBranchAddress("trkjet_vz", &trkjet_vz, &b_trkjet_vz);
   fChain->SetBranchAddress("trkjet_p", &trkjet_p, &b_trkjet_p);
   fChain->SetBranchAddress("trkjet_pt", &trkjet_pt, &b_trkjet_pt);
   fChain->SetBranchAddress("trkjet_phi", &trkjet_phi, &b_trkjet_phi);
   fChain->SetBranchAddress("trkjet_ntracks", &trkjet_ntracks, &b_trkjet_ntracks);
   fChain->SetBranchAddress("trkjet_truetp_sumpt", &trkjet_truetp_sumpt, &b_trkjet_truetp_sumpt);
   fChain->SetBranchAddress("trueMET", &trueMET, &b_trueMET);
   fChain->SetBranchAddress("trkMET", &trkMET, &b_trkMET);
   fChain->SetBranchAddress("trkMHT", &trkMHT, &b_trkMHT);
   fChain->SetBranchAddress("trkHT", &trkHT, &b_trkHT);
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
