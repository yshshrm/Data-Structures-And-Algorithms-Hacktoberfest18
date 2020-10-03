#interpolation search will be applicable only for sorted arrays and has is also faster and efficient then binary search

def int_search(l,new,ele):
    low=0
    high=l-1
    while(low<=high and new[low]<=ele<=new[high]):
        mid=low+int(((float(high-low)/(new[high]-new[low]))*(ele-new[low])))
        if(new[mid]==ele): #element found
            return mid
        else:
            if(new[mid]<ele): # ele is in second half 
                low=mid+1
            else:             #ele is in first half
                high=mid-1
    return -1  #element not found
    
    
arr=raw_input("Enter the elements of the array with spaces in between for interpolation search : ").split(" ")
new=[]
for i in arr: #converting all the string elements to integer
    a=int(i)
    new.append(a)
l=len(new) #length of the new int array
ele=int(raw_input("Enter a number : ")) #element to be searched
res=int_search(l,new,ele)
if(res!=-1):
    print("Element  found")
else:
    print("Element not found")
