#ifndef L1SUMS_H
#define L1SUMS_H
#include "NtupleContent.h"
#include <typeinfo>

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/L1TCorrelator/interface/TkHTMiss.h"
#include "DataFormats/L1TCorrelator/interface/TkEtMiss.h"



template<typename INPUT>
class L1Sums{
  public:
    L1Sums(const edm::EDGetTokenT<INPUT> &L1SumToken_ ,const edm::Event &iEvent)
    {
        iEvent.getByToken(L1SumToken_, L1Sum);
    };
    ~L1Sums(){};
    
    void FillBranches(NtupleContent &nt, std::string Col){
      *(nt.GetScalarBranch(Col+"_et"))= L1Sum->begin()->et();
      *(nt.GetScalarBranch(Col+"_phi"))= L1Sum->begin()->phi();
      *(nt.GetScalarBranch(Col+"_etTotal"))= L1Sum->begin()->etTotal();
    };
   
   
  private:
    edm::Handle<INPUT> L1Sum;
};
#endif
