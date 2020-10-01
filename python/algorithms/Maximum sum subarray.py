array=[int(i) for i in input().split( )]

def find_crossing_subarr(array,start,mid,end):
    sm=0
    left_sum=-99999
    right_sum=-1000000
    
    for i in  range(mid,start-1,-1):
        sm = sm + array[i]
        if(sm > left_sum):
            left_sum=sm
            
    for i in range(mid+1,len(array)-1):
        sm =sm +array[i]
        if(sm > right_sum):
            right_sum=sm
            
    return left_sum + right_sum
        
    
    
def find_max_subarr(array,start,end):
    
    if(end==start):
        return array[start]
    
    mid= (start + end )//2
    
    return max(find_max_subarr(array,start,mid),find_max_subarr(array,mid+1,end),find_crossing_subarr(array,start,mid,end)) 

maxi_sum =find_max_subarr(array,0,len(array)-1)         


print(maxi_sum)
