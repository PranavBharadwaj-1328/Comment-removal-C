import os
#from commentmulti import multirem

def multirem(f):
    os.system("touch out.c")
    f1 = open(f,"r")
    lol = 0
    lines = f1.readlines()
    with open("out.c","w") as f2:
        for line in lines:
            if (line.find("/*") == -1 and lol == 0):
                f2.write(line)
            else:
                if line.find("/*") != -1:
                    lol = 1
                    f2.write(line[0:line.find("/*")])
                if line.find("*/") != -1:
                    lol = 0
                    f2.write(line[line.find("*/")+2:])

def removecomment():
    a = input('Enter File to process:')
    cmd = "touch out1.c"
    os.system(cmd)
    with open("out1.c","w") as f:
        with open(a,"r") as f1:
            lines = f1.readlines()
            for line in lines:
                if ("//" in line):
                    x = line.split("//")
                    f.write(x[0]+"\n")
                else:
                    f.write(line)
    f.close()
    f1.close()
    multirem("out1.c")
    #os.system("rm "+a)
    os.system("rm out1.c")

removecomment()
