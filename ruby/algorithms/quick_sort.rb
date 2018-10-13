def quick_sort(a,low,high)
  if low<high
      p=partition(a,low,high)
      quick_sort(a,low,p-1)
      quick_sort(a,p+1,high)
  end
return a
end

def partition(a,low,high)
 i=low
 j=high+1
 pivot= a[low]
  while true
      begin
          i+=1
          break if i==high
      end while a[i]<pivot
      begin 
          j-=1
          break if j==low
      end while a[j]>pivot
      break if i>=j
      temp=a[i]
      a[i]=a[j]
      a[j]=temp
  end
  temp=a[low]
  a[low]=a[j]
  a[j]=temp
  return j
end

p quick_sort([12,3,1,2,4,70,89,3,3],0,8)