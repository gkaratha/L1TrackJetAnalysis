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

    edm::EDGetTokenT< std::vector<l1t::TkJet> > FastJetsToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > TrackJetsToken_;
    edm::EDGetTokenT< std::vector<reco::GenJet> > GenJetsToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > FastJetsExtToken_;
    edm::EDGetTokenT< std::vector<l1t::TkJet> > TrackJetsExtToken_;
    edm::EDGetTokenT< std::vector<TTTrack<Ref_Phase2TrackerDigi_>> > L1TrkToken_;
    edm::EDGetTokenT< std::vector<TTTrack<Ref_Phase2TrackerDigi_>> > L1TrkExtToken_;
    edm::EDGetTokenT< TTTrackAssociationMap<Ref_Phase2TrackerDigi_> > GenTrackInfoToken_;
    edm::EDGetTokenT< std::vector<l1t::TkEtMiss> > EtMissToken_;
    edm::EDGetTokenT< std::vector<l1t::TkHTMiss> > HtMissToken_;
    edm::EDGetTokenT< std::vector<l1t::TkPrimaryVertex> > PVToken_;
       
    
    double L1GenJetMatchDR_=0.3;
    bool AddExtendedL1Jets_=true;
    bool AddExtendedL1Tracks_=true;
    edm::Service<TFileService> fs;
    TTree * t1;
    NtupleContent nt;
}; 

//constructor
L1TJetTrackAnalyzer::L1TJetTrackAnalyzer(const edm::ParameterSet& iConfig):
    FastJetsToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("FastJetsInputTag") ) },
    TrackJetsToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("TrackJetsInputTag") )},
    GenJetsToken_{ consumes<std::vector<reco::GenJet>>( iConfig.getParameter <edm::InputTag> ("GenJetsInputTag") ) },
    FastJetsExtToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("FastJetsExtInputTag") ) },
    TrackJetsExtToken_{ consumes<std::vector<l1t::TkJet>>( iConfig.getParameter <edm::InputTag> ("TrackJetsExtInputTag") )},
    L1TrkToken_{ consumes<std::vector<TTTrack<Ref_Phase2TrackerDigi_>>> ( iConfig.getParameter <edm::InputTag> ("TracksInputTag") ) },
    L1TrkExtToken_{ consumes<std::vector<TTTrack<Ref_Phase2TrackerDigi_>>> ( iConfig.getParameter <edm::InputTag> ("TracksExtInputTag") ) },
    GenTrackInfoToken_{ consumes<TTTrackAssociationMap<Ref_Phase2TrackerDigi_>>( iConfig.getParameter <edm::InputTag> ("GenTrackInfoInputTag") )},
    EtMissToken_{consumes< std::vector<l1t::TkEtMiss> >(iConfig.getParameter<edm::InputTag>("EtMissInputTag")) },
    HtMissToken_{consumes<std::vector<l1t::TkHTMiss> > (iConfig.getParameter<edm::InputTag>("HTMissInputTag"))},
    PVToken_{ consumes< std::vector<l1t::TkPrimaryVertex>> (iConfig.getParameter<edm::InputTag> ("PVInputTag")) },
    L1GenJetMatchDR_{iConfig.getParameter<double>("L1GenJetMatchDR")},
    AddExtendedL1Jets_{iConfig.getParameter<bool>("AddExtendedL1Jets")},
    AddExtendedL1Tracks_{iConfig.getParameter<bool>("AddExtendedL1Tracks")}
{}

L1TJetTrackAnalyzer::~L1TJetTrackAnalyzer(){};

void
L1TJetTrackAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){

  nt.ClearBranches();
  L1Vtx L1PVs(PVToken_,iEvent);
  L1PVs.FillBranches(nt);
  L1Jet TrackJets(TrackJetsToken_,iEvent);
  TrackJets.FillBranches("TrackJet",nt);  
  L1Jet FastJets(FastJetsToken_,iEvent);
  FastJets.FillBranches("FastJet",nt);
  
  L1Track L1Tracks(L1TrkToken_, iEvent);
  L1Tracks.FillBranches("Track",nt);
  L1Sums<std::vector<l1t::TkEtMiss>> MET(EtMissToken_,iEvent);
  MET.FillBranches(nt,"MET");
  L1Sums<std::vector<l1t::TkHTMiss>> MHT(HtMissToken_,iEvent);
  MHT.FillBranches(nt,"MHT");

  L1Jet TrackJetsExt;
  L1Jet FastJetsExt;
  L1Track L1TracksExt;

  if ( AddExtendedL1Jets_){
    TrackJetsExt.ReadData(TrackJetsExtToken_,iEvent);
    TrackJetsExt.FillBranches("TrackJetExt",nt);
    FastJetsExt.ReadData(FastJetsExtToken_,iEvent);
    FastJetsExt.FillBranches("FastJetExt",nt);
    L1TracksExt.ReadData(L1TrkToken_,iEvent);
    L1TracksExt.FillBranches("TrackExt",nt);
  }  

  if ( !iEvent.isRealData() ){
    TrackJets.AddMCBranches("TrackJet",nt);
    FastJets.AddMCBranches("FastJet",nt);
    GJet GenJets(GenJetsToken_,iEvent);
    GenJets.FillBranches(nt);
    GenJets.MatchToReco("FastJet",L1GenJetMatchDR_,nt);
    GenJets.MatchToReco("TrackJet",L1GenJetMatchDR_,nt);
    L1Tracks.FillMCBranches( GenTrackInfoToken_,iEvent,"Track",nt);
    if ( AddExtendedL1Jets_){
       TrackJetsExt.AddMCBranches("TrackJet",nt);
       FastJetsExt.AddMCBranches("FastJetExt",nt);   
       GenJets.MatchToReco("FastJetExt",L1GenJetMatchDR_,nt);
       GenJets.MatchToReco("TrackJetExt",L1GenJetMatchDR_,nt);
       L1TracksExt.FillMCBranches( GenTrackInfoToken_,iEvent,"TrackExt",nt);
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
