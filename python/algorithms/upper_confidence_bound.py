# Importing the libraries
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math

# Importing the dataset
# dataset=pd.read_csv('ad.csv')

'''
Step 1: At each round n, we consider two numbers for each ad i,
        i. the number of times i was selected upto round n
        ii. the sum of rewards of the ad i upto round n
Step 2: From these two numbers we compute:
        i. the average reward of i upto round n
        ii. the confidence level at round n
Step 3: We select the i with maximum upper confidence bound
'''
    
# Implementing UCB
N=10000
d=10
ads_selected=[]
number_of_selections=[0]*d
sums_of_rewards=[0]*d
total_reward=0
for n in range(0,N):
    ad=0
    max_upperbound=0
    for i in range(0,d):
        if(number_of_selections[i]>0):
            average_reward=sums_of_rewards[i]/number_of_selections[i]
            delta_i=math.sqrt(3/2*math.log(n+1)/number_of_selections[i])
            upper_bound=average_reward+delta_i
        else:
            upper_bound=1e400
        if(upper_bound > max_upperbound):
            max_upperbound=upper_bound
            ad=i
    ads_selected.append(ad)
    number_of_selections[ad]+=1
    reward=dataset.values[n,ad]
    sums_of_rewards[ad]+=reward
    total_reward=total_reward+reward
            
# Visualising the UCB results
plt.hist(ads_selected)
plt.title('Histogram of Ads seletions')
plt.xlabel('Ads selected')
plt.ylabel('Number of times each ad was seected')
plt.show()