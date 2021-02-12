import ROOT as rt
import os

sr_signal=2798.
sr_comb_bkg=234.
sr_partial_bkg=263.
lowersb_comb_bkg=216.
lowersb_partial_bkg=1756.
uppersb_comb_bkg=226.


rt.gROOT.SetBatch(True)
data = rt.TFile("KJpsiEE_Data_MCDataBDT/histos.root","READ")
vrs= ["hxgb"]
output_folder="KJpsiEE_SubtractData_MCDataBDT"

comb_histos={}
partial_histos={} 
signal_histos={}



#"hptb","hsLxy","hptmu1","hptmu2","hptk","hcos"
for var in vrs:
  comb_histos[var]=None
  partial_histos[var]=None
  signal_histos[var]=None

for var in comb_histos.keys():
  histo=data.Get(var+"_upper")
  histo.Scale(uppersb_comb_bkg/histo.Integral())
  comb_histos[var]=histo

for var in partial_histos.keys():
  histo=data.Get(var+"_lower")
  comb_histo=comb_histos[var]
  histo.Scale((lowersb_comb_bkg+lowersb_partial_bkg)/histo.Integral())
  comb_histo.Scale(lowersb_comb_bkg/comb_histo.Integral())
  histo.Add(comb_histo,-1)
  for ibin in range(0,histo.GetNbinsX()):
    if histo.GetBinContent(ibin)<0:
       histo.SetBinContent(ibin,0)
  histo.Scale((lowersb_partial_bkg)/histo.Integral())
  partial_histos[var]=histo

for var in signal_histos.keys():
  histo=data.Get(var+"_sr")
  comb_histo=comb_histos[var]
  partial_histo=partial_histos[var]
  histo.Scale((sr_comb_bkg+sr_partial_bkg+sr_signal)/histo.Integral())
  comb_histo.Scale(sr_comb_bkg/comb_histo.Integral())
  partial_histo.Scale(sr_partial_bkg/partial_histo.Integral())
  histo.Add(comb_histo,-1)
  histo.Add(partial_histo,-1)
  for ibin in range(0,histo.GetNbinsX()):
    if histo.GetBinContent(ibin)<0:
       histo.SetBinContent(ibin,0)
  histo.Scale((sr_signal)/histo.Integral())
  signal_histos[var]=histo

os.system("mkdir -p "+output_folder)
fout = rt.TFile(output_folder+"/histos.root","RECREATE")
for var in signal_histos.keys():
  signal_histos[var].Write()
fout.Write()
fout.Close()


exit()

