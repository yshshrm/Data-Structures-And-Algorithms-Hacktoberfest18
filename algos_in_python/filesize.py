def file_sizes():
	file=open('file_sizes.txt','w')

	for i in range(30,1001,10):
		file.write(str(i)+"\n")
	file.close()
