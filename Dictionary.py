# Python 3 code to demonstrate 
# working of fromkeys() 

# initializing sequence 
seq = { 'a', 'b', 'c', 'd', 'e' } 

# using fromkeys() to convert sequence to dict 
# initializing with None 
res_dict = dict.fromkeys(seq) 

# Printing created dict 
print ("The newly created dict with None values : " + str(res_dict)) 


# using fromkeys() to convert sequence to dict 
# initializing with 1 
res_dict2 = dict.fromkeys(seq, 1) 

# Printing created dict 
print ("The newly created dict with 1 as value : " + str(res_dict2)) 

