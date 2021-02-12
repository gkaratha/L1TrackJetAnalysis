#include "tree_class.h"
#include "canvasses.h"

int jet_basic(){
 
  TChain * cc =new TChain("L1TrackNtuple/eventTree");
//  cc->Add("/eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Jan20/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU0/210120_104033/0000/*.root");
  //cc->Add(" /eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Jan20/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU140/210120_104059/0000/*.root");
//cc->Add(" /eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Jan20/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU140/210120_104059/0001/*.root");
//cc->Add(" /eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Jan20/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU140/210120_104059/0002/*.root");
  cc->Add("/eos/cms/store/cmst3/user/gkaratha/L1Tracker_2021Jan20/TT_TuneCP5_14TeV-powheg-pythia8/crab_data_TTbar_PU200/210120_152528/0000/*.root");
  int nentries=cc->GetEntries();
  nentries=100000;
  float dr_cut=0.3;


  tree_class jets;
  jets.Init(cc);



  TH1F * hdr_2l= new TH1F("hdr_2l","",50,0,0.5);
  TH1F * hdr_trk= new TH1F("hdr_trk","",50,0,0.5);
  TH1F * heff_den= new TH1F("heff_den","",50,0,1000);
  TH1F * heff_2l_num= new TH1F("heff_2l_num","",50,0,1000);
  TH1F * heff_trk_num= new TH1F("heff_trk_num","",50,0,1000);
  TH1F * heffeta_den= new TH1F("heffeta_den","",50,-2.6,2.6);
  TH1F * heffeta_2l_num= new TH1F("heffeta_2l_num","",50,-2.6,2.6);
  TH1F * heffeta_trk_num= new TH1F("heffeta_trk_num","",50,-2.6,2.6);
  TH1F * hresol_incl= new TH1F("hresol_incl","",50,-0.5,0.5);
  TH2F * hresol_2d= new TH2F("hresol_2d","",50,-0.5,0.5,50,0,1000);  
  
  

  cout<<nentries<<"  "<<cc->GetEntries()<<endl;
  for (int ievt=0; ievt<nentries; ievt++){
    if (ievt%10000==0) cout<<ievt<<endl;
    jets.GetEntry(ievt);
    for ( int igj=0; igj<jets.genjet_pt->size(); igj++){
       TLorentzVector genjet;
       genjet.SetPtEtaPhiM(jets.genjet_pt->at(igj),jets.genjet_eta->at(igj),jets.genjet_phi->at(igj),0); 
       heff_den->Fill(genjet.Pt());
       if (genjet.Pt()>300) heffeta_den->Fill(genjet.Eta());
       float minDR=1000;
       int match_itrkj=-1;
       for ( int itrkj=0; itrkj<jets.trkjet_pt->size(); itrkj++){
         TLorentzVector trkjet;
         trkjet.SetPtEtaPhiM(jets.trkjet_pt->at(itrkj),jets.trkjet_eta->at(itrkj),jets.trkjet_phi->at(itrkj),0);
         if( trkjet.DeltaR(genjet)>minDR ) continue;
         minDR=trkjet.DeltaR(genjet);
         match_itrkj=itrkj;              
       }
       hdr_trk->Fill(minDR);
       if (minDR>dr_cut) match_itrkj=-1;
       if (match_itrkj>-1){
          heff_trk_num->Fill(genjet.Pt());
          if (genjet.Pt()>300) heffeta_trk_num->Fill(genjet.Eta());
       }
       minDR=1000;
       int match_i2lj=-1;
       for ( int i2lj=0; i2lj<jets.ltrkjet_pt->size(); i2lj++){
         TLorentzVector l1jet;
         l1jet.SetPtEtaPhiM(jets.ltrkjet_pt->at(i2lj),jets.ltrkjet_eta->at(i2lj),jets.ltrkjet_phi->at(i2lj),0);
         if( l1jet.DeltaR(genjet)>minDR ) continue;
         minDR=l1jet.DeltaR(genjet);
         match_i2lj=i2lj;
       }
       hdr_2l->Fill(minDR);
       if (minDR>dr_cut) match_i2lj=-1;
       if (match_i2lj>-1){
         heff_2l_num->Fill(genjet.Pt());
         if (genjet.Pt()>300) heffeta_2l_num->Fill(genjet.Eta());
       }
       if (match_i2lj>-1 && match_itrkj>-1){
          float resol= (jets.ltrkjet_pt->at(match_i2lj)- jets.trkjet_pt->at(match_itrkj))/jets.trkjet_pt->at(match_itrkj);
          hresol_incl->Fill(resol);
          hresol_2d->Fill(resol,jets.trkjet_pt->at(match_itrkj));  
       }
    }
  }


heff_den->SetBinContent(heff_den->GetNbinsX(),
          heff_den->GetBinContent(heff_den->GetNbinsX()+1)+heff_den->GetBinContent(heff_den->GetNbinsX()) 
          );
heff_2l_num->SetBinContent(heff_2l_num->GetNbinsX(),
          heff_2l_num->GetBinContent(heff_2l_num->GetNbinsX()+1)+heff_2l_num->GetBinContent(heff_2l_num->GetNbinsX()) 
          );
heff_trk_num->SetBinContent(heff_trk_num->GetNbinsX(),
          heff_trk_num->GetBinContent(heff_trk_num->GetNbinsX()+1)+heff_trk_num->GetBinContent(heff_trk_num->GetNbinsX()) 
          );
hresol_incl->SetBinContent(1,
          hresol_incl->GetBinContent(0)+hresol_incl->GetBinContent(1)
          );
hresol_incl->SetBinContent(hresol_incl->GetNbinsX(),
          hresol_incl->GetBinContent(hresol_incl->GetNbinsX())+hresol_incl->GetBinContent(hresol_incl->GetNbinsX()+1)
          );
     

heff_2l_num->Divide(heff_den);
heff_trk_num->Divide(heff_den);
heffeta_2l_num->Divide(heffeta_den);
heffeta_trk_num->Divide(heffeta_den);

TCanvas * c1= canvas_1plot(hdr_trk,"hdr_trk",false,"#Delta R","");
c1->SaveAs("cdr_trk.png");
TCanvas * c2= canvas_1plot(hdr_2l,"hdr_2l",false,"#Delta R","");
c2->SaveAs("cdr_2l.png");
TCanvas * c3= canvas_2plot_ratio(heff_2l_num,heff_trk_num,"heffpt",false,false,0,1.05,"p_{T}(GEN)","","2-layer","FastJet");
c3->SaveAs("ceffpt.png");
TCanvas * c4= canvas_2plot_ratio(heffeta_2l_num,heffeta_trk_num,"heffeta",false,false,0,1.05,"#eta(GEN)","","2-layer","FastJet");
c4->SaveAs("ceffeta.png");
TCanvas * c5= canvas_1plot(hresol_incl,"hresol",true,"(p_{T}^{2l}-p_{T}^{Fast})/p_{T}^{Fast}","");
c5->SetLogy();
c5->SaveAs("cresol.png");
TCanvas *c7 = canvas_2d(hresol_2d,"resol_2d", "(p_{T}^{2l}-p_{T}^{Fast})/p_{T}^{Fast}", "p_{T}^{Fast}","COLZ");
c7->SetLogz();
c7->SaveAs("cresol2d.png");

return 0;
}
