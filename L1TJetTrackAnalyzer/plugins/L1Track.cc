#include "L1Track.h"


L1Track::L1Track(const edm::EDGetTokenT <std::vector<TTTrack<Ref_Phase2TrackerDigi_>>> & L1TrkToken_, const edm::Event &iEvent ){
  iEvent.getByToken(L1TrkToken_, L1Tracks);
}

L1Track::~L1Track(){}

void
L1Track::ReadData( const edm::EDGetTokenT <std::vector<TTTrack<Ref_Phase2TrackerDigi_>>> & L1TrkToken_, const edm::Event &iEvent ){
  iEvent.getByToken(L1TrkToken_, L1Tracks);
}

void
L1Track::FillBranches(std::string Col, NtupleContent &nt){
  unsigned int ntrk=0;
  for(auto & trk: *L1Tracks){
 //   std::cout<<trk.momentum().perp()<<std::endl;
    (nt.GetBranch(Col+"_pt"))->emplace_back(trk.momentum().perp());
    (nt.GetBranch(Col+"_eta"))->emplace_back(trk.momentum().eta());
    (nt.GetBranch(Col+"_phi"))->emplace_back(trk.momentum().phi());
    (nt.GetBranch(Col+"_z0"))->emplace_back(trk.z0());
    (nt.GetBranch(Col+"_nFitPars"))->emplace_back(trk.nFitPars());    
   // std::cout<<trk.nFitPars()<<std::endl;
    if (trk.nFitPars()==5){
       (nt.GetBranch(Col+"_x0"))->emplace_back(trk.POCA().x());
       (nt.GetBranch(Col+"_y0"))->emplace_back(trk.POCA().y());
       (nt.GetBranch(Col+"_d0"))->emplace_back( - trk.POCA().x() *sin(trk.momentum().phi()) + trk.POCA().y()*cos(trk.momentum().phi()) );
    } else{
       (nt.GetBranch(Col+"_x0"))->emplace_back(-99);
       (nt.GetBranch(Col+"_y0"))->emplace_back(-99);
       (nt.GetBranch(Col+"_d0"))->emplace_back(-99);
    }
    (nt.GetBranch(Col+"_chi2"))->emplace_back(trk.chi2());
    (nt.GetBranch(Col+"_chi2xy"))->emplace_back(trk.chi2XY());
    (nt.GetBranch(Col+"_chi2z"))->emplace_back(trk.chi2Z());
    (nt.GetBranch(Col+"_stubConsistency"))->emplace_back(trk.stubPtConsistency());
    ntrk+=1;    
    passed_idxs.emplace_back(&trk-&(L1Tracks->at(0)));
  }
  *(nt.SetNCol("n"+Col))=ntrk;

}


void
L1Track::FillMCBranches(const edm::EDGetTokenT<TTTrackAssociationMap<Ref_Phase2TrackerDigi_> > &GenTrackInfoToken_, const edm::Event &iEvent, std::string Col, NtupleContent &nt){
 //  edm::Handle< TTTrackAssociationMap<Ref_Phase2TrackerDigi_> > MCTrkAssociation;
   iEvent.getByToken(GenTrackInfoToken_,MCTrkAssociation);
   for(unsigned int &idx: passed_idxs){
     edm::Ptr<TTTrack<Ref_Phase2TrackerDigi_>> trk_ptr(L1Tracks, idx);
     if (MCTrkAssociation->isLooselyGenuine(trk_ptr) ) 
        (nt.GetBranch(Col+"_isLooseGenuineMC"))->emplace_back(1);
     else
        (nt.GetBranch(Col+"_isLooseGenuineMC"))->emplace_back(0);
     if (MCTrkAssociation->isGenuine(trk_ptr) )
        (nt.GetBranch(Col+"_isGenuineMC"))->emplace_back(1);
     else
        (nt.GetBranch(Col+"_isGenuineMC"))->emplace_back(0);
     if (MCTrkAssociation->isUnknown(trk_ptr) )
        (nt.GetBranch(Col+"_isUnknownMC"))->emplace_back(1);
     else
        (nt.GetBranch(Col+"_isUnknownMC"))->emplace_back(0);
     if (MCTrkAssociation->isCombinatoric(trk_ptr) )
        (nt.GetBranch(Col+"_isCombinatoricMC"))->emplace_back(1);
     else
        (nt.GetBranch(Col+"_isCombinatoricMC"))->emplace_back(0);
     float pt=-99,eta=-99,phi=-99,pdg=-99,x0=-99,z0=-99,y0=-99,dxy=-99,d0=-99; 
     if ( MCTrkAssociation->isGenuine(trk_ptr) || MCTrkAssociation->isLooselyGenuine(trk_ptr) ){
         edm::Ptr<TrackingParticle> gentrk_ptr = MCTrkAssociation->findTrackingParticlePtr(trk_ptr);
         if ( !gentrk_ptr.isNull()){
            pt=gentrk_ptr->p4().pt();
            eta=gentrk_ptr->p4().eta();
            phi=gentrk_ptr->p4().phi();
            pdg=gentrk_ptr->pdgId();
            x0=gentrk_ptr->vertex().x();
            y0=gentrk_ptr->vertex().y();
            z0=gentrk_ptr->vertex().z();
            dxy=sqrt(x0*x0+y0*y0);
            d0=(-x0*sin(phi)+y0*cos(phi));
         }
     }
     (nt.GetBranch(Col+"_gen_pt"))->emplace_back(pt);
     (nt.GetBranch(Col+"_gen_eta"))->emplace_back(eta);
     (nt.GetBranch(Col+"_gen_phi"))->emplace_back(phi);
     (nt.GetBranch(Col+"_gen_pdgId"))->emplace_back(pdg);
     (nt.GetBranch(Col+"_gen_x0"))->emplace_back(x0);
     (nt.GetBranch(Col+"_gen_y0"))->emplace_back(y0);
     (nt.GetBranch(Col+"_gen_z0"))->emplace_back(z0);
     (nt.GetBranch(Col+"_gen_dxy"))->emplace_back(dxy);
     (nt.GetBranch(Col+"_gen_d0"))->emplace_back(d0);
   }

}
