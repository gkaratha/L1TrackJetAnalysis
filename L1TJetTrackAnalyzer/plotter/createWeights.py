import ROOT as rt
import sys

sys.path.insert(1, '/afs/cern.ch/work/g/gkaratha/private/SUSYCMG/HLT/efficiency/Analizer/CMGforRk/CMSSW_10_4_0/src/CMGTools/RKAnalysis/python/plotter')
from pyroot_canvas import  *


rt.gROOT.SetBatch(True)

mc_src_file="KJpsiEE_MC_PUweight_MCDataBDT/histos.root"
data_src_file="KJpsiEE_SubtractData_MCDataBDT/histos.root"
mc_target_file="MC_PUStudy_target/histos.root"
data_target_file="Data_PUStudy_target/histos.root"
histo="hxgb_sr"
Xaxis="N_{pv}"
function_name="XGBweight"
test_weight_file=False
weight_function_in_cpp=False  #for plotter.py 
weight_function_in_python=True 



fmc= rt.TFile(mc_src_file,"READ")
fdata= rt.TFile(data_src_file,"READ")
hmc=fmc.Get(histo)
hdata=fdata.Get(histo)
hmc.Scale(1./hmc.Integral())
hdata.Scale(1./hdata.Integral())
hweighted=hmc.Clone()

weights=[]
for i in range(1,hmc.GetNbinsX()):
  if hmc.GetBinContent(i)==0:
    weights.append(0)
  else:
    weights.append(float(hdata.GetBinContent(i))/hmc.GetBinContent(i))
  hweighted.SetBinContent(i,weights[-1]*hmc.GetBinContent(i))
 

cnowgt = canvas_Nplots( [hdata,hmc],"cnowgt",False,True,0.001,0.15,Xaxis,"",["Data","MC"],[1,2])
cnowgt.SaveAs(histo+"_noweight.png")
cwgt = canvas_Nplots( [hdata,hweighted],"cwgt",False,True,0.001,0.15,Xaxis,"",["Data","MC"],[1,2])
cwgt.SaveAs(histo+"_weight.png")

if test_weight_file:
  ftrg_mc= rt.TFile(mc_target_file,"READ")
  htrg_mc=ftrg_mc.Get(histo)
  ftrg_data= rt.TFile(data_target_file,"READ")
  htrg_data=ftrg_data.Get(histo)
  htrg_mc.Scale(1./htrg_mc.Integral())
  htrg_data.Scale(1./htrg_data.Integral())
  htrg_weighted=htrg_mc.Clone()
  for i in range(1,htrg_mc.GetNbinsX()):
    htrg_weighted.SetBinContent(i,weights[i]*htrg_mc.GetBinContent(i))

  ctarget = canvas_Nplots( [htrg_data,htrg_weighted],"ctarget",False,True,0.001,0.15,Xaxis,"",["Data","MC"],[1,2])
  ctarget.SaveAs(histo+"_target.png")

if weight_function_in_cpp:
  with open(function_name+".h",'w') as txt:
    txt.write("float "+function_name+"(float PU){\n") 
    for iwght,weight in enumerate(weights):
      txt.write("if (PU=="+str(iwght)+") return "+str(weight)+";\n")
    txt.write("return 0.0; }") 
  txt.close() 
    
if weight_function_in_python:
  with open(function_name+".py",'w') as txt:
    txt.write("def "+function_name+"(PU):\n")
    for iwght,weight in enumerate(weights):
      txt.write("  if PU<"+str(iwght*0.25+5.5)+": return "+str(weight)+";\n")
    txt.write("  return 0.0")
  txt.close()

