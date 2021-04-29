///////////////////////////////////////////////////////////////////////////////
//    L1T track and track-based objects analyzer
//
//    Original Author: G. Karathanasis, georgios.karathanasis@cern.ch, Colorando
//    Boulder
//    Based on the code of Emily MacDonald, emily.macdonald@cern.ch, Colorando
//    Boulder
///////////////////////////////////////////////////////////////////////////////



//FRAMEWORK HEADERS
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

//DATA FORMATS HEADERS
#include "SimTracker/TrackTriggerAssociation/interface/TTTrackAssociationMap.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticle.h"
#include "DataFormats/L1TrackTrigger/interface/TTTypes.h"
#include "DataFormats/L1TrackTrigger/interface/TTTrack.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/L1TCorrelator/interface/TkJet.h"
#include "DataFormats/L1TCorrelator/interface/TkPrimaryVertex.h"
#include "DataFormats/L1TCorrelator/interface/TkHTMiss.h"
#include "DataFormats/L1TCorrelator/interface/TkEtMiss.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"


//COMMON TOOLS
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/Ref.h"

//Internal package classes
#include "NtupleContent.h"
#include "L1Jet.h"
#include "GJet.h"
#include "L1Track.h"
#include "L1Vtx.h"
#include "L1Sums.h"
#include "helper.h"


class L1TJetTrackAnalyzer: public edm::one::EDAnalyzer<edm::one::SharedResources,edm::one::WatchRuns>  {

  public:
    // Constructor/destructor
    explicit L1TJetTrackAnalyzer(const edm::ParameterSet& iConfig);
    ~L1TJetTrackAnalyzer() override;
    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

  private:
    virtual void beginJob() override;
    void         beginRun(edm::Run const& iEvent, edm::EventSetup const&) ;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    void         endRun(edm::Run const& iEvent, edm::EventSetup const&);
    virtual void endJob() override;

    edm::EDGetTokenT< reco::BeamSpot > BeamSpotToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > FastJetsToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > TwoLayerJetsToken_;
    edm::EDGetTokenT< std::vector<reco::GenJet> > GenJetsToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > FastJetsExtToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > TwoLayerJetsExtToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > TrackingJetsToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > TrackingJetsExtToken_;
    edm::EDGetTokenT< std::vector<TTTrack<Ref_Phase2TrackerDigi_>> > L1TrkToken_;
    edm::EDGetTokenT< std::vector<TTTrack<Ref_Phase2TrackerDigi_>> > L1TrkExtToken_;
    edm::EDGetTokenT< TTTrackAssociationMap<Ref_Phase2TrackerDigi_> > GenTrackInfoToken_;
    edm::EDGetTokenT< TTTrackAssociationMap<Ref_Phase2TrackerDigi_> > GenExtTrackInfoToken_;
    edm::EDGetTokenT< std::vector<l1t::TkEtMiss> > EtMissToken_;
    edm::EDGetTokenT< std::vector<l1t::TkHTMiss> > HtMissToken_;
    edm::EDGetTokenT< std::vector<l1t::TkPrimaryVertex> > PVToken_;
    edm::EDGetTokenT< std::vector<reco::GenParticle> > GenPartToken_;       
    
    double L1GenJetMatchDR_=0.3;
    bool AddExtendedL1Jets_=true;
    bool AddExtendedL1Tracks_=true;
    bool SkipMCBranches_=false;
    edm::Service<TFileService> fs;
    TTree * t1;
    NtupleContent nt;
}; 

//constructor
L1TJetTrackAnalyzer::L1TJetTrackAnalyzer(const edm::ParameterSet& iConfig):
    BeamSpotToken_{ consumes<reco::BeamSpot> (iConfig.getParameter<edm::InputTag>("BeamSpotInputTag")) },
    FastJetsToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("FastJetsInputTag") ) },
    TwoLayerJetsToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("TwoLayerJetsInputTag") )},
    GenJetsToken_{ consumes<std::vector<reco::GenJet>>( iConfig.getParameter <edm::InputTag> ("GenJetsInputTag") ) },
    FastJetsExtToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("FastJetsExtInputTag") ) },
    TwoLayerJetsExtToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("TwoLayerJetsExtInputTag") )},
    TrackingJetsToken_{consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("TrackingJetsInputTag") )},
    TrackingJetsExtToken_{consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("TrackingJetsExtInputTag") )},     
    L1TrkToken_{ consumes<std::vector<TTTrack<Ref_Phase2TrackerDigi_>>> ( iConfig.getParameter <edm::InputTag> ("TracksInputTag") ) },
    L1TrkExtToken_{ consumes<std::vector<TTTrack<Ref_Phase2TrackerDigi_>>> ( iConfig.getParameter <edm::InputTag> ("TracksExtInputTag") ) },
    GenTrackInfoToken_{ consumes<TTTrackAssociationMap<Ref_Phase2TrackerDigi_>>( iConfig.getParameter <edm::InputTag> ("GenTrackInfoInputTag") )},
    GenExtTrackInfoToken_{ consumes<TTTrackAssociationMap<Ref_Phase2TrackerDigi_>>( iConfig.getParameter <edm::InputTag> ("GenExtTrackInfoInputTag") )},
    EtMissToken_{consumes< std::vector<l1t::TkEtMiss> >(iConfig.getParameter<edm::InputTag>("EtMissInputTag")) },
    HtMissToken_{consumes<std::vector<l1t::TkHTMiss> > (iConfig.getParameter<edm::InputTag>("HTMissInputTag"))},
    PVToken_{ consumes< std::vector<l1t::TkPrimaryVertex> > (iConfig.getParameter<edm::InputTag> ("PVInputTag")) },
    GenPartToken_{ consumes< std::vector<reco::GenParticle> > (iConfig.getParameter<edm::InputTag> ("GenPartInputTag")) },
    L1GenJetMatchDR_{iConfig.getParameter<double>("L1GenJetMatchDR")},
    AddExtendedL1Jets_{iConfig.getParameter<bool>("AddExtendedL1Jets")},
    AddExtendedL1Tracks_{iConfig.getParameter<bool>("AddExtendedL1Tracks")},
    SkipMCBranches_{iConfig.getParameter<bool>("SkipMCBranches")}
{}

L1TJetTrackAnalyzer::~L1TJetTrackAnalyzer(){};

void
L1TJetTrackAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){

  nt.ClearBranches();
  edm::Handle<reco::BeamSpot> BeamSpot;
  iEvent.getByToken(BeamSpotToken_, BeamSpot); 
  edm::Handle<std::vector<l1t::TkJet>> TkJets;
  iEvent.getByToken(TwoLayerJetsToken_, TkJets);
  if ( !TkJets.isValid() ) {
    std::cout << "\nWarning: TkJetCollection not found in the event. Exit\n";
    return;
  }
  if ( AddExtendedL1Jets_ ) {
    edm::Handle<std::vector<l1t::TkJet>> TkJetsExt;
    iEvent.getByToken(TwoLayerJetsExtToken_, TkJetsExt);
    if ( !TkJetsExt.isValid() ) {
      std::cout << "\nWarning: TkJetCollection not found in the event. Exit\n";
      return;
    }
  }
  nt.RunNumber=iEvent.id().run(); 
  nt.LumiSection=iEvent.luminosityBlock();  
  nt.EventNumber=iEvent.id().event();
  nt.Beamspot_x= BeamSpot->x0(); 
  nt.Beamspot_y= BeamSpot->y0();
  nt.Beamspot_z= BeamSpot->z0();
  L1Vtx L1PVs(PVToken_,iEvent);
  L1PVs.FillBranches(nt);
  L1Track L1Tracks(L1TrkToken_, iEvent);
  L1Tracks.FillBranches("Track",nt);

  L1Jet TwoLayerJets(TwoLayerJetsToken_,iEvent);
  TwoLayerJets.FillBranches("TwoLayerJet","Track",nt);  
  L1Jet FastJets(FastJetsToken_,iEvent);
  FastJets.FillBranches("FastJet","Track",nt);
  
  L1Sums<std::vector<l1t::TkEtMiss>> MET(EtMissToken_,iEvent);
  MET.FillBranches(nt,"MET");
  L1Sums<std::vector<l1t::TkHTMiss>> MHT(HtMissToken_,iEvent);
  MHT.FillBranches(nt,"MHT");

  edm::Handle<std::vector<reco::GenParticle> > GenParticles;
  iEvent.getByToken(GenPartToken_, GenParticles);

  L1Jet TwoLayerJetsExt;
  L1Jet FastJetsExt;
  L1Track L1TracksExt;

  L1Jet TrackingJets;
  L1Jet TrackingJetsExt;

  if ( AddExtendedL1Jets_){
    L1TracksExt.ReadData(L1TrkExtToken_,iEvent);
    L1TracksExt.FillBranches("TrackExt",nt);
    TwoLayerJetsExt.ReadData(TwoLayerJetsExtToken_,iEvent);
    TwoLayerJetsExt.FillBranches("TwoLayerJetExt","TrackExt",nt);
    FastJetsExt.ReadData(FastJetsExtToken_,iEvent);
    FastJetsExt.FillBranches("FastJetExt","TrackExt",nt);
  }  

  if ( !iEvent.isRealData() && !SkipMCBranches_ ){
    TrackingJets.ReadData(TrackingJetsToken_,iEvent);
    TrackingJets.FillBranches("TrackingJet","Track",nt);
    TwoLayerJets.AddMCBranches("TwoLayerJet",nt);
    TrackingJets.AddMCBranches("TrackingJet",nt);
    FastJets.AddMCBranches("FastJet",nt);
    GJet GenJets(GenJetsToken_,GenPartToken_,iEvent);
    GenJets.FillBranches(nt);
    GenJets.MatchToReco("FastJet",L1GenJetMatchDR_,nt);
    GenJets.MatchToReco("TwoLayerJet",L1GenJetMatchDR_,nt);
    GenJets.MatchToReco("TrackingJet",L1GenJetMatchDR_,nt);
    CollectionMatcher("TrackingJet","TwoLayerJet",L1GenJetMatchDR_,nt);
    L1Tracks.FillMCBranches( GenTrackInfoToken_,iEvent,"Track",nt);
    if ( AddExtendedL1Jets_){
       TrackingJetsExt.ReadData(TrackingJetsExtToken_,iEvent);
       TrackingJetsExt.FillBranches("TrackingJetExt","TrackExt",nt);
       TwoLayerJetsExt.AddMCBranches("TwoLayerJetExt",nt);
       FastJetsExt.AddMCBranches("FastJetExt",nt);   
       TrackingJetsExt.AddMCBranches("TrackingJetExt",nt);
       GenJets.MatchToReco("FastJetExt",L1GenJetMatchDR_,nt);
       GenJets.MatchToReco("TwoLayerJetExt",L1GenJetMatchDR_,nt);
       GenJets.MatchToReco("TrackingJetExt",L1GenJetMatchDR_,nt);
       CollectionMatcher("TrackingJetExt","TwoLayerJetExt",L1GenJetMatchDR_,nt);
       L1TracksExt.FillMCBranches( GenExtTrackInfoToken_,iEvent,"TrackExt",nt);
    }
  }

  t1->Fill();
}

void
L1TJetTrackAnalyzer::beginJob(){
  t1=fs->make<TTree>("Events","Events");
  nt.SetTree(t1);
  nt.CreateBranches();
}

void
L1TJetTrackAnalyzer::beginRun(edm::Run const& run,  edm::EventSetup const& iSetup){}

void
L1TJetTrackAnalyzer::endRun(edm::Run const& run,  edm::EventSetup const& iSetup){}

void
L1TJetTrackAnalyzer::endJob(){}


void
L1TJetTrackAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(L1TJetTrackAnalyzer);
