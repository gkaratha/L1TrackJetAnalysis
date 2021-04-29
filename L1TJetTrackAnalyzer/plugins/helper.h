#ifndef L1TJETTRACKANALYZER_HELPER_H
#define L1TJETTRACKANALYZER_HELPER_H
#include "NtupleContent.h"
#include <string>
#include <vector>
#include "DataFormats/Math/interface/deltaR.h"


void
CollectionMatcher(string Col1_, string Col2_, double MaxDRcone_, NtupleContent & nt){
  for(unsigned int idx=0; idx<(nt.GetBranch(Col2_+"_pt"))->size(); idx++){
    (nt.GetBranch(Col2_+"_matchedTo"+Col1_+"Idx"))->emplace_back(-99);
    (nt.GetBranch(Col2_+"_matchedTo"+Col1_+"Dr"))->emplace_back(99);
  }
 
  for(unsigned int idx=0; idx<(nt.GetBranch(Col1_+"_pt"))->size(); idx++){
    double minDR2=99*99;
    int matchIdx=-99;
    for(unsigned int idx2=0; idx2<(nt.GetBranch(Col2_+"_pt"))->size(); idx2++){
       double DR2=reco::deltaR2((nt.GetBranch(Col2_+"_eta"))->at(idx2),
                               (nt.GetBranch(Col2_+"_phi"))->at(idx2),
                               (nt.GetBranch(Col1_+"_eta"))->at(idx),
                               (nt.GetBranch(Col1_+"_phi"))->at(idx) );
       if (DR2>minDR2 || DR2>MaxDRcone_*MaxDRcone_) continue;
       matchIdx=idx2;
       minDR2=DR2;
   }
   (nt.GetBranch(Col1_+"_matchedTo"+Col2_+"Idx"))->emplace_back(matchIdx);
   (nt.GetBranch(Col1_+"_matchedTo"+Col2_+"Dr"))->emplace_back(sqrt(minDR2));
   if (matchIdx>-1){
      (nt.GetBranch(Col2_+"_matchedTo"+Col1_+"Idx"))->at(matchIdx)=idx;
      (nt.GetBranch(Col2_+"_matchedTo"+Col1_+"Dr"))->at(matchIdx)=sqrt(minDR2);
   }
  }
}

#endif
