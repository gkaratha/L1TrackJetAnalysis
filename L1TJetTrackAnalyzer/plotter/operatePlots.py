import ROOT as rt
from argparse import ArgumentParser
import os

def plot_cnv(histos,name,legs=None,xaxis=""):
  c1=rt.TCanvas("c1","c1",700,700);
  leg=rt.TLegend(0.65,0.75,0.9,0.9)
  for ihst,histo in enumerate(histos):
    histo.SetLineColor(ihst+1)
    histo.SetLineWidth(2)
    if legs!=None:
      leg.AddEntry(histo,legs[ihst])
    histo.GetXaxis().SetTitle(xaxis)
    if ihst>0:
      histo.Draw("HIST sames")
    else:
      histo.Draw("HIST ")
  if legs!=None:
    leg.Draw("sames");
  c1.SaveAs(name+".png") 
  


if __name__ == "__main__":
   parser = ArgumentParser()
   ''' performs histo1+histo2 or histo1-histo2, for multiple hitos'''
   parser.add_argument("-i","--inputPath",dest="inputPath", type=str, default="plots.root", help="input directories to find histos.root")   
   parser.add_argument("--histo1Names", nargs='+', dest="histo1Names", default=["SimplePlots"],type=str, help=" name of first plot bunch. takes input list or single file or * wildcard (eg *sgnbkg NOT *_signbkg)")
   parser.add_argument("--histo2Names", nargs='+', dest="histo2Names", default=["SimplePlots"],type=str, help=" name of second plot bunch. This should be equal in number to bunch1 ")
   parser.add_argument("--histo1ScaleYield",dest="histo1ScaleYield",type=float,default=0,help="normalize all #1 plots")
   parser.add_argument("--histo2ScaleYield",dest="histo2ScaleYield",type=float,default=0,help="normaliuze all #2 plots")
   parser.add_argument("--operationSymbol",dest="operationSymbol",type=str, default="",help="Add with + subtract with -")
   parser.add_argument("--ext",dest="ext",type=str, default="",help="naming stuff of output plots: put --ext ext -> name_ext")
   parser.add_argument("--debug",dest="debug",type=bool,default=False,help="saves plots before and after operation")
   args=parser.parse_args()
   rt.gROOT.SetBatch(True)

   if args.operationSymbol!="+" and args.operationSymbol!="-":
     print "select + for operationSymbol for adding, and - for subracting two histos "
   
   file_in = rt.TFile(args.inputPath+"/histos.root","READ");
   os.system("mkdir -p "+args.inputPath+"/Operated")
   file_out = rt.TFile(args.inputPath+"/Operated/histos.root","RECREATE");
   
   if len(args.histo1Names)==1 and args.histo1Names[0].startswith("*"):    
     identify=(args.histo1Names[0].split("*"))[1]     
     args.histo1Names=[]
     for hst in file_in.GetListOfKeys():
       if "_"+identify in hst.GetName(): args.histo1Names.append(hst.GetName())

   if len(args.histo2Names)==1 and args.histo2Names[0].startswith("*"):
     identify=(args.histo2Names[0].split("*"))[1]
     args.histo2Names=[]
     for hst in file_in.GetListOfKeys():
       if "_"+identify in hst.GetName(): args.histo2Names.append(hst.GetName())

   for name1,name2 in zip(args.histo1Names,args.histo2Names):
     file_in.cd()
     histo1 = file_in.Get(name1)
     histo2 = file_in.Get(name2)
     print name1,name2
     if args.debug:
        print "before scale",histo1.Integral(),histo2.Integral()
        plot_cnv([histo1,histo2],"h_before_scale",["Sgn+Bkg","Bkg"],"p_{T}(e1)")
     if args.histo1ScaleYield > 0: histo1.Scale(args.histo1ScaleYield/histo1.Integral())
     if args.histo2ScaleYield > 0: histo2.Scale(args.histo2ScaleYield/histo2.Integral())
     if args.debug:
        print "after scale",histo1.Integral(),histo2.Integral()
        plot_cnv([histo1,histo2],"h_after_scale",["Sgn+Bkg","Bkg(Scaled)"],"p_{T}(e1)")
     if args.operationSymbol=="-":
        histo1.Add(histo2,-1)
        if args.ext!="":
           histo1.SetName(histo1.GetName().split("_")[0]+args.ext)
        else:
           histo1.SetName(histo1.GetName()+"_sub_"+histo2.GetName())
     else:
        histo1.Add(histo2,+1)
        if args.ext!="":
           histo1.SetName(histo1.GetName().split("_")[0]+args.ext)
        else:
           histo1.SetName(histo1.GetName()+"_add_"+histo2.GetName())
     if args.debug:
        print "result h1+/-h2",histo1.Integral()
        plot_cnv([histo1],"h_result",None,"p_{T}(e1)")
     file_out.cd()
     histo1.Write()
     file_out.Write()
       
   
