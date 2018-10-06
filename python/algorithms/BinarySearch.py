#binary search will be applicable only for sorted arrays

def bin_search(low,high,new,ele):
    if (high>=low): 
        mid=low+(high-low)/2 #getting the middle element
        if(ele==new[mid]):
            print("Element is found") # if it is the middle element
        elif(new[mid]>ele):
            bin_search(low,mid-1,new,ele) #recursive search by setting new value of high
        else:
            bin_search(mid+1,high,new,ele) #recursive search by setting new value of low
    else:
        print("Element not found") 

arr=raw_input("Enter the elements of the array with spaces in between for binary search : ").split(" ")
new=[]
for i in arr: #converting all the string elements to integer
    a=int(i)
    new.append(a)
l=len(new) #length of the new int array
ele=int(raw_input("Enter a num")) #element to be searched

#setting low high and mid elements
low=0
high=l-1

bin_search(low,high,new,ele)

'''
sample input :
1 2 3 4 5
4
sample output:
Element found
Explanation :
Initially low is 0 and high is 5
When we go to bin_search function, the array "new" is like this
 
1 2 3 4 5
L   M   H
 
when ele != mid,
new positions of L M H are
1 2 3 4 5
      L H
      M
      
Since mid element is equal to the reqd element, answer is element is found 
'''
