from os import walk
from os import listdir
import argparse


if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("-p","--paths", dest="paths", nargs='+', type=str, help="paths of directories of files")
  parser.add_argument("-o","--outputName", dest="output", default="testmca", type=str, help="output txt name (dont put .txt exists)")

  args = parser.parse_args()
  lines=""
  for path in args.paths:
    for (dirpath, dirnames, filenames) in walk(path):
       if len(filenames)>0 and "root" in filenames[0]:
         for fl in filenames:
           if "root" in fl: lines+=dirpath+"/"+fl+"\n"
         break;
       elif len(dirnames)>0 and ("root" in listdir(dirpath+"/"+dirnames[0])[0]):
         for fl in dirnames:
           lines+=dirpath+"/"+fl+"/*.root\n"
         break;

  with open(args.output+".txt","w") as out:
    out.write(lines)
  out.close()
    
   
