def permuteUtil(str,count,result,level):
        # here we determine that we are at last level of recurision and print the resulting 
        # array
        if(level == len(result)):
                print(result)
                return
        
        for i in range(len(str)): 
                # ignore the character if its count is 0
                if(count[i]==0):
                        continue
                result[level]=str[i]
                count[i] -= 1
                #since we are movind down one level we decerement the count
                #of character we used.
                permuteUtil(str,count,result,level+1)
                #after coming out of from level we againt increment the count
                #which we decreased
                count[i] +=1

def permute(inputstring):
    charMap = dict()
    for key in inputstring:
            if(key in charMap.keys()):
                    charMap[key]+=1
            else:
                    charMap[key]=1
    # characters list will store all unique letters of string
    characters = sorted(charMap.keys())
    # count will store count of characters
    count = list(map(lambda x:charMap[x],characters))
    # result will store word to be printed and will decide our level of recursion
    result = [0 for x in range(len(inputstring))]
    str = []
    for c in characters:
            str.append(c)
    permuteUtil(str,count,result,0)# 0 is our first level of recursion
    



inputstring = ["A","R","I","H","A","N","T"]
permute(inputstring);
