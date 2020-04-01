# --- MODULAR EXPONENTIATION --- 
print "to calaculate (a^b) mod c"
print "enter a : "
a=int(raw_input())
print "enter b : "
b=int(raw_input())
print "enter c : "
c=int(raw_input())
i=1
ans=1
while (i <= b):
	ans= (ans * a) % c
	i=i+1
print "("+str(a)+"^"+str(b)+") mod "+str(c)+" = " + str(ans)
