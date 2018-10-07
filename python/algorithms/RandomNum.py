#AUTHOR: TarunApp
#GITHUB: https://github.com/TarunApp
#Code can be edited and used freely
#Also, please check out the repository rules as well

import random
import time

alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

listascii = ' !"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~'
o = list(listascii)

#This function returns a characters based on the size of the Alphabhet string
def randstring(v):
    random.seed(time)
    for i in range(v):
        print(str(alphabet[random.randint(0,26)]))

#This function returns characters based on the size of the ASCII string
def randstring2(v):
    random.seed(time)
    for i in range(v):
        print(o[random.randint(0,111)])

#If there are any edits needed, let me know!

