hiii = [6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95, 106, 111, 115, 118, 119, 122, 123, 129, 133, 134, 141, 142, 143, 145, 146, 155, 158, 159, 161, 166, 177, 178, 183, 185, 187, 194, 201, 202]
#print(hiii)
asads = len(hiii)
t = input()
t = int(t)
for i in range(t):
	n = input()
	n = int(n)
	for j in range(asads-1):
			for k in range(asads):
				if(hiii[j]+hiii[k]==n):
					print("YES")
					n = -1
					break
				elif(hiii[j]+hiii[k]>n):
					break
			if(n==-1):
				n = -2
				break
	if(n!=-2):
		print("NO")

