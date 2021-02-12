import root_numpy
import matplotlib.pyplot as plt


def scatter_plot(varX,varY,legX='var1',legY='var2',name='scatter',labels=[]):
    if len(labels)>0:
      for varx, vary,color,mrk,lbl in zip(varX,varY,['grey','red','blue'],["o","+","x"],labels):
        plt.scatter(x=varx,y=vary,c=color,marker=mrk,alpha=0.5,s=70,label=lbl)
    else:
      for varx, vary,color,mrk in zip(varX,varY,['grey','red','blue'],["o","+","x"]):
        plt.scatter(x=varx,y=vary,c=color,marker=mrk,alpha=0.5,s=70)
    plt.legend()
    plt.ylabel(legY,fontsize=15)
    plt.xlabel(legX,fontsize=15)
    plt.xlim(-0.7,0)
    plt.ylim(0,1.5)
    plt.title('CMS Preliminary',loc="left",fontweight="bold")
    plt.savefig(name+".png")
    plt.close()

root_fl="L1Jets_new.root"
branches=["Track_eta","Track_phi","FastJet_L1Trk_eta","FastJet_L1Trk_phi","TrackJet_L1Trk_eta","TrackJet_L1Trk_phi"]
evt_number=100



data= root_numpy.root2array(root_fl, treename='L1TrackNtuple/Events',branches=branches)
data=root_numpy.rec2array(data)

trk_eta=[];  trk_phi=[]; fastjet_eta=[]; fastjet_phi=[]; 
trkjet_eta=[]; trkjet_phi=[]
for ievt,evt in enumerate(data):
  if ievt!=1: continue
  objs={"trk_eta":evt[0], "trk_phi":evt[1], "fastjets_eta":evt[2], "fastjets_phi":evt[3], "trkjets_eta":evt[4], "trkjets_phi":evt[5]}
  for eta in objs["trk_eta"]:
    trk_eta.append(eta)
  for phi in objs["trk_phi"]: 
    trk_phi.append(phi)
  for jet in objs["trkjets_eta"]:
    for eta in jet:
      trkjet_eta.append(eta)
  for jet in objs["trkjets_phi"]:
    for phi in jet:
      trkjet_phi.append(phi)  
  for jet in objs["fastjets_eta"]:
    for eta in jet:
      fastjet_eta.append(eta)
  for jet in objs["fastjets_phi"]:
    for phi in jet:
      fastjet_phi.append(phi)

scatter_plot([trk_eta,trkjet_eta,fastjet_eta],[trk_phi,trkjet_phi,fastjet_phi],legX='eta',legY='phi',name='scatter',labels=["L1 tracks","2-layer","FastJet"])
