# This module will generate 97 * 5 files,here 5 is for 5 
# variation of data of same length


import random
from filesize import *


def makingFiles():
      print("\n\n Making files \n\n")
      file_sizes()
      for i in range(30,1001,10):                                          # This will generate 97 files
            for j in range(1,6):                                           # This will make 5 variation for file of size i
                  fileName="files/Data_Size="+str(i)+"_Var="+str(j)+".txt"
                  file=open(fileName,'w')                                  # Make a file

                  for k in range(i):

                        randomNumber=random.randint(1,1000) 
                        file.write(str(randomNumber)+"\n")
                                                                           # for loop ends
            
                  file.close()
                                                                           #2nd for loop ends
      print("\n\n Done....File made \n\n")

                                                      

            
            
      
