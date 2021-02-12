#include "tree_class.h"
#include "canvasses.h"

int JetPerformance(){
  TChain * cc =new TChain("L1TrackNtuple/Events");
  cc->Add("/eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Feb10/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU0/210210_174619/0000/*.root");

  TString name="chrE";

  tree_class tree;
  tree.Init(cc);

  cout<<cc->GetEntries()<<endl;

  TH1F * hpt_den= new TH1F("hpt_den","",100,0,1000);
  TH1F * hpt_trkj= new TH1F("hpt_trkj","",100,0,1000);
  TH1F * hpt_fastj= new TH1F("hpt_fastj","",100,0,1000);
  TH1F * hpt_den_eta1p2= new TH1F("hpt_den_eta1p2","",100,0,1000);
  TH1F * hpt_trkj_eta1p2= new TH1F("hpt_trkj_eta1p2","",100,0,1000);
  TH1F * hpt_fastj_eta1p2= new TH1F("hpt_fastj_eta1p2","",100,0,1000);
  TH1F * hpt_den_eta2p4= new TH1F("hpt_den_eta2p4","",100,0,1000);
  TH1F * hpt_trkj_eta2p4= new TH1F("hpt_trkj_eta2p4","",100,0,1000);
  TH1F * hpt_fastj_eta2p4= new TH1F("hpt_fastj_eta2p4","",100,0,1000);
  TH2F * heta_phi_den= new TH2F("heta_phi_den","",48,-2.4,2.4,60,-3.2,3.2);
  TH2F * heta_phi_fast= new TH2F("heta_phi_fast","",48,-2.4,2.4,60,-3.2,3.2);
  TH2F * heta_phi_trk= new TH2F("heta_phi_trk","",48,-2.4,2.4,60,-3.2,3.2);
  TH2F * hntrl_pt_den= new TH2F("hntrl_pt_den","",50,0,1000,50,0,1);
  TH2F * hntrl_pt_found= new TH2F("hntrl_pt_found","",50,0,1000,50,0,1);
  TH2F * hntrl_pt_not= new TH2F("hntrl_pt_not","",50,0,1000,50,0,1);
  TH1F * hresol_pt= new TH1F("hresol_pt","",100,-1,1);
  TH1F * hresol_visE= new TH1F("hresol_visE","",100,-1,1);
  TH1F * hresol_chrgE= new TH1F("hresol_chrgE","",100,-1,1);
  TH1F * hresol_fast= new TH1F("hresol_fast","",100,-1,1);
  TH1F * hresol_trk= new TH1F("hresol_trk","",100,-1,1);
  TH1F * hresol_fst_trk= new TH1F("hresol_fst_trk","",100,-1,1);
  TH1F * hresol_fst_trk_org= new TH1F("hresol_fst_trk_org","",100,-1,1);
  TH1F * hresol_fst_trk_eta1p2= new TH1F("hresol_fst_trk_eta1p2","",100,-1,1);
  TH1F * hresol_fst_trk_eta2p4= new TH1F("hresol_fst_trk_eta2p4","",100,-1,1);

  

  float nfastj=0,ntrkj=0,nboth=0,nnone=0;
  for (int ievt=0; ievt<100000; ievt++){
    tree.GetEntry(ievt);
    
    for (int igen=0; igen<tree.GenJet_eta->size(); igen++){
      float eta_gen=tree.GenJet_eta->at(igen);
//      float pt_gen=tree.GenJet_pt->at(igen);
      float pt_gen= tree.GenJet_neutralEmE->at(igen)+ tree.GenJet_neutralHadronE->at(igen) + tree.GenJet_chargedEmE->at(igen)+ tree.GenJet_chargedHadronE->at(igen) + tree.GenJet_muonE->at(igen);
      float phi_gen=tree.GenJet_phi->at(igen);
      float ntrlE = tree.GenJet_neutralEmE->at(igen)+ tree.GenJet_neutralHadronE->at(igen);
      pt_gen-=ntrlE;
      float visE=tree.GenJet_neutralEmE->at(igen)+ tree.GenJet_neutralHadronE->at(igen) + tree.GenJet_chargedEmE->at(igen)+ tree.GenJet_chargedHadronE->at(igen) + tree.GenJet_muonE->at(igen);

      if (fabs(eta_gen)>2.4) continue;
      hpt_den->Fill(pt_gen);
      heta_phi_den->Fill(eta_gen,phi_gen);
      hntrl_pt_den->Fill(pt_gen,ntrlE/pt_gen);
      if( fabs(eta_gen)<1.2 )
         hpt_den_eta1p2->Fill(pt_gen);
      else 
         hpt_den_eta2p4->Fill(pt_gen);

      if( tree.GenJet_matchedToFastJetIdx->at(igen)>-1){
        nfastj++;
        hpt_fastj->Fill(pt_gen);
        heta_phi_fast->Fill(eta_gen, phi_gen);
        int ifast = tree.GenJet_matchedToFastJetIdx->at(igen);
        if( fabs(eta_gen)<1.2 ) 
           hpt_fastj_eta1p2->Fill(pt_gen);
        else 
           hpt_fastj_eta2p4->Fill(pt_gen);
        hntrl_pt_found->Fill(pt_gen,ntrlE/pt_gen);
        TLorentzVector vj;
        vj.SetPtEtaPhiM(tree.GenJet_pt->at(igen),tree.GenJet_eta->at(igen),tree.GenJet_phi->at(igen),0);        
        TLorentzVector vreco; 
        vreco.SetPtEtaPhiM(tree.FastJet_pt->at(ifast),tree.FastJet_eta->at(ifast),tree.FastJet_phi->at(ifast),0);
        hresol_pt->Fill((vreco.E()-vj.E())/vj.E());
        hresol_visE->Fill((vreco.E()-visE)/visE);
        hresol_chrgE->Fill((vreco.E()-(visE-ntrlE))/(visE-ntrlE));
        hresol_fast->Fill((vreco.E()-(visE-ntrlE))/(visE-ntrlE));
      }

      if( tree.GenJet_matchedToFastJetIdx->at(igen)<0)
         hntrl_pt_not->Fill(pt_gen,ntrlE/pt_gen);

      if( tree.GenJet_matchedToTrackJetIdx->at(igen)>-1){
         ntrkj++;
         hpt_trkj->Fill(pt_gen);
         heta_phi_trk->Fill(eta_gen,phi_gen);
         if( fabs(eta_gen)<1.2 ) 
           hpt_trkj_eta1p2->Fill(pt_gen);
         else  hpt_trkj_eta2p4->Fill(pt_gen);
         int itrk = tree.GenJet_matchedToTrackJetIdx->at(igen);
         TLorentzVector vreco;
         vreco.SetPtEtaPhiM(tree.TrackJet_pt->at(itrk),tree.TrackJet_eta->at(itrk),tree.TrackJet_phi->at(itrk),0);
         hresol_trk->Fill((vreco.E()-(visE-ntrlE))/(visE-ntrlE));
      }
      if( tree.GenJet_matchedToFastJetIdx->at(igen)>-1 
          && tree.GenJet_matchedToTrackJetIdx->at(igen)>-1){
          nboth+=1;
          int itrk = tree.GenJet_matchedToTrackJetIdx->at(igen);
          int ifst = tree.GenJet_matchedToFastJetIdx->at(igen);
          TLorentzVector vtrkj;
          vtrkj.SetPtEtaPhiM(tree.TrackJet_pt->at(itrk),tree.TrackJet_eta->at(itrk),tree.TrackJet_phi->at(itrk),0);
          TLorentzVector vfstj;
          vfstj.SetPtEtaPhiM(tree.FastJet_pt->at(ifst),tree.FastJet_eta->at(ifst),tree.FastJet_phi->at(ifst),0);
          hresol_fst_trk_org->Fill((vtrkj.E()-vfstj.E())/vfstj.E());
          float resol=(vtrkj.E()-vfstj.E())/vfstj.E();
          if (resol>0) resol=(vtrkj.E()-vfstj.E())/vtrkj.E();
          hresol_fst_trk->Fill(resol);
          if ( fabs(eta_gen)<1.2) hresol_fst_trk_eta1p2->Fill(resol);
          else hresol_fst_trk_eta2p4->Fill(resol);
      }
      if( tree.GenJet_matchedToFastJetIdx->at(igen)<0
          && tree.GenJet_matchedToTrackJetIdx->at(igen)<0 ) nnone+=1;
        
     
    }
  }

  cout<<"nfastj= "<<nfastj<<" ntrkj= "<<ntrkj<<" nboth= "<<nboth<<" nnone= "<<nnone<<endl;
  hpt_trkj->Divide(hpt_den);
  hpt_fastj->Divide(hpt_den);
  hpt_trkj_eta1p2->Divide(hpt_den_eta1p2);
  hpt_fastj_eta1p2->Divide(hpt_den_eta1p2);
  hpt_trkj_eta2p4->Divide(hpt_den_eta2p4);
  hpt_fastj_eta2p4->Divide(hpt_den_eta2p4);
  heta_phi_fast->Divide(heta_phi_den);
  heta_phi_trk->Divide(heta_phi_den);
  hntrl_pt_found->Divide(hntrl_pt_den);
  hntrl_pt_not->Divide(hntrl_pt_den);

  TCanvas * c1 = canvas_2plot_ratio(hpt_trkj,hpt_fastj,"c1",false,false,0,1.05,"charged E.","","2-Layer","FastJet");
  TCanvas * c2 = canvas_2plot(hpt_trkj_eta1p2,hpt_fastj_eta1p2,"c2",false,false,0,1.05,"charged E.","","2-Layer","FastJet");
  TCanvas * c3 = canvas_2plot(hpt_trkj_eta2p4,hpt_fastj_eta2p4,"c3",false,false,0,1.05,"charged E.","","2-Layer","FastJet");
  TCanvas * c4= canvas_2d(heta_phi_fast,"c4","#eta","#phi");
  TCanvas * c5= canvas_2d(heta_phi_trk,"c5","#eta","#phi");
  TCanvas * c6= canvas_2d(hntrl_pt_found,"c6","Visible E","Neutral Fraction");
  TCanvas * c7= canvas_2d(hntrl_pt_not,"c7","Visible E","Neutral Fraction");
  TCanvas * c8 = canvas_3plot(hresol_pt,hresol_visE,hresol_chrgE,"c8",true,true,0.0001,1,"","","Total","Visible","Charged");
  TCanvas * c9 = canvas_2plot(hresol_trk,hresol_fast,"c9",true,true,0.0001,0.1,"pT","","TrackJet","FastJet");
  hresol_fst_trk->SetBinContent(1,hresol_fst_trk->GetBinContent(0)+hresol_fst_trk->GetBinContent(1));
  hresol_fst_trk_org->SetBinContent(100,hresol_fst_trk_org->GetBinContent(101)+hresol_fst_trk_org->GetBinContent(100));
  TCanvas * c10 = canvas_1plot( hresol_fst_trk_org,"c10",true,"","");
  TCanvas * c11 = canvas_1plot( hresol_fst_trk,"c11",true,"","");
  TCanvas * c12 = canvas_1plot( hresol_fst_trk_eta1p2,"c12",true,"","");
  TCanvas * c13 = canvas_1plot( hresol_fst_trk_eta2p4,"c13",true,"","");

  c1->SaveAs("eff_incl_"+name+".png");
  c2->SaveAs("eff_eta1p2_"+name+".png"); 
  c3->SaveAs("eff_eta2p4_"+name+".png");
  c4->SaveAs("eff2d_fast_"+name+".png");
  c5->SaveAs("eff2d_trk_"+name+".png");
  c6->SaveAs("eff2d_found_"+name+".png");
  c8->SaveAs("resol_gen_"+name+".png");
  c9->SaveAs("resol_trk_fast_"+name+".png");
  c10->SaveAs("resol_orig_"+name+".png");
  c11->SaveAs("resol_"+name+".png");
  c12->SaveAs("resol_eta1.2_"+name+".png");
  c13->SaveAs("resol_eta2.4_"+name+".png");
  return 0;
}
