#include<stdio.h>

void *binary_search(void *key,void *array, size_t num ,size_t size,int(*cmp)(const void *,const void *) )
{
	size_t left = 0;
	size_t right = num - 1;

	while(left <= right){
		size_t index = (right + left)>>1 ;
		void *ptr = array + (index * size);
		int val = cmp(key, ptr);

		if(val==0)
			return ptr;
		else if(val < 0)
			right = index - 1;
		else
			left = index + 1;
	}
	return NULL;
}
