
#Activity-Selection Problem in python3.6
def activity(A,s,f):
	f=sorted(f)
	S=set([])
	S.add(A[0])
	
	k=0
	n=len(A)
	
	for i in range(1,n):
		if s[i]>=f[k]:
			S.add(A[i])
			k=i
			
	return S
	
	
A=[int(x) for x in input().split(" ")]


s=[int(x) for x in input().split(" ")]


f=[int(x) for x in input().split(" ")]

print (activity(A,s,f))