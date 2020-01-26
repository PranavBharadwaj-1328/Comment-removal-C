# Comment Removal Program in python submitted by K Pranav Bharadwaj 17MCME06
import os

# To remove multi line comments 
def multirem(f):
    os.system("touch out.c")
    f1 = open(f,"r")
    flag = 0
    lines = f1.readlines()
    with open("out.c","w") as f2:
        for line in lines:
            if (line.find("/*") == -1 and flag == 0):
                f2.write(line)
            else:
                if line.find("/*") != -1:
                    flag = 1
                    f2.write(line[0:line.find("/*")])
                if line.find("*/") != -1:
                    flag = 0
                    f2.write(line[line.find("*/")+2:])

def removecomment():
    print('Enter the file name in ""')
    a = input('Enter File to process:')
    cmd = "touch out1.c"
    os.system(cmd)
    # To remove single line comments
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
    # This output is given as input to multirem command
    multirem("out1.c")
    #os.system("rm "+a)
    os.system("rm out1.c")
    os.system("mv out.c "+a)

removecomment()
