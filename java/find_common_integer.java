import java.util.*;

public int findCommonInteger(int[] a){
	int counter = 1;
	int popular = a[0];
	int tempCount, temp = 0;
	for (int i = 0; i < (a.length - 1); i++){
		counter = a[i];
		for(int j = 1; j < a.length; j++){
			if(temp == a[j]){
				tempCount++;
			}
		}
		if (tempCount > count){
			popular = temp;
			count = tempCount;
		}
	}
	return popular
}