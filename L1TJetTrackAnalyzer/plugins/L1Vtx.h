#ifndef L1VTX_H
#define L1VTX_H

#include "NtupleContent.h"
#include <vector>
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/L1TCorrelator/interface/TkPrimaryVertex.h"


class L1Vtx{
  public:
    L1Vtx(const edm::EDGetTokenT<std::vector<l1t::TkPrimaryVertex> >& PVtxToken_, const edm::Event &iEvent){
     iEvent.getByToken(PVtxToken_, PVtx);
    };
    ~L1Vtx(){};

    void  FillBranches(NtupleContent &nt){
       nt.nPV=0;
       for( auto &vtx: *PVtx){
         nt.PV_z0.emplace_back(vtx.zvertex());
         nt.PV_sum.emplace_back(vtx.sum());
         nt.nPV++;
       }
    }

  private:
    edm::Handle<std::vector<l1t::TkPrimaryVertex>> PVtx;

};

#endif
