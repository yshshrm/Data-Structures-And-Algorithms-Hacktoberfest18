def insertionsort(array):
	comparison=0
	
	for i in range(1,len(array)):
		hole=array[i]
		position=i-1
		while position !=-1:
			comparison+=1
			if(array[position]>hole):
				array[position+1]=array[position]
				position-=1
			else:
				break;
		
		array[position+1]=hole

	return  comparison
