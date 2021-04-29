from histo_tool import *
from ROOT import *
from cms_lumi import CMS_lumi
import os

def PerSamplePlot(sample_names,sample_roots,workdir,outputDir):
  fout = TFile(outputDir+"/histos.root","RECREATE")
  yld = open(outputDir+"/Yields.txt","w")
  yld.write("HistoName    |    Total Yields(intgr)\n")
  with open(workdir+"/_histo_0.txt","r") as res:
    lines=[]
    lines=res.readlines()
    for iline,line in enumerate(lines):
      if line=="\n": continue
      wline=(line.rstrip()).split(":")
      histName=wline[0]
      canvasName=wline[1]
      plot_options=(wline[2]).split(";")
      c1 = TCanvas( canvasName,canvasName, 700,700)
      defalut_canvas(c1)
      if "LogX" in plot_options: c1.SetLogx()
      if "LogY" in plot_options: c1.SetLogy()
      x1,y1,x2,y2= legPos(plot_options)
      leg = TLegend(x1,y1,x2,y2)
      ichunk=-1;
      finternal = TFile(workdir+"/temp.root","RECREATE")
      names=[]
      for sample_nm,sample_root in zip(sample_names,sample_roots):
        ichunk+=1
        froot = TFile(workdir+"/"+sample_root)
        h1 = (froot.Get(histName)).Clone(histName+str(ichunk))
        names.append(histName+str(ichunk))
        if "Over" in plot_options: h1=AddOverflow(h1)
        yld.write(histName+"  "+sample_nm+"  "+str(h1.Integral(0,h1.GetNbinsX()+1))+"\n")
        h1=default_plot(h1)
        h1.SetLineWidth(3)
        h1=transform(h1,plot_options)
        if "Norm" in plot_options:
           h1.Scale(1.0/h1.Integral())
        fout.cd()
        h1.Write()
        finternal.cd()
        h1.Write()

      finternal.Close()
      finternal_read= TFile(workdir+"/temp.root","READ")
      hstack= THStack("hs","")
      for iplot,name in enumerate(names):
        htemp=finternal_read.Get(name)
        xaxe= str(htemp.GetXaxis().GetTitle())
        yaxe= str(htemp.GetYaxis().GetTitle())
        hstack.SetTitle(";"+xaxe+";"+yaxe) 
        htemp.SetLineColor(1+iplot)
        leg.AddEntry(htemp,legName(plot_options,sample_names[iplot]))
        hstack.Add(htemp);
      if "PlotMarker" in plot_options:
          hstack.Draw("nostack,e1p")
      else:
          hstack.Draw("nostack,hist")
        
      CMS_lumi(c1, 4,  0 , aLittleExtra=0.07)
      leg.Draw("sames")
      c1.SaveAs(outputDir+"/"+canvasName+".png");
      c1.SaveAs(outputDir+"/"+canvasName+".pdf");
  yld.close()
  fout.Close()
