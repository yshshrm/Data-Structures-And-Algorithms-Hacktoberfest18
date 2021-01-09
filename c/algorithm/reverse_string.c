  /**

 * @file
 				 	Reverse String
 * 	  
 * @brief   finding the reverse of any string using two pointer approach      
 
 */

# include<stdio.h>
# include<stdlib.h>

/*
 			* swapped the value 
 @param a   A refrence call to i-th character of input string
 @param b   A refrece call to j-th character of input string
 
*/
void swap(char *a , char *b)
{ 


char temp = '\0';
temp =*a;
*a = *b;
*b= temp;
return ;

}



/**
 	* Reverse the String -- "str"
 
 * @param str     string which has to reverse.
 * @param size     size of string
 * @return        reversed string
 
 */
char * reverseString(char str[],int size)
{
	// Dyanamically allocating memory for character array 
	char *string = (char *) malloc(size*sizeof(char));
	
	int x;
	for(x=0;x<size;x++)
	{	string[x] = str[x];		
			}
			
	// since we have made an array of characters , so in order to make it string , let's terminate it with NULL character		
	string[x]='\0';	
	
		
	if(size==1)		
	return string;
	
/*  
  
  	# input :  string ( A Y U S H )
  				        i       j
  				   
  	* step 1 :  string ( H Y U S A )
  					       i   j
  					  
  	* step 2 :  string ( H S U Y A )
  					        ij
  					    
  	
  	return  :  string( H S U Y A ) 

 	
	
*/	

	int i=0,j=size-1;
	
	for(;i<j;i++,j--)
	{ 
	 swap(&string[i],&string[j]);	  
	
	}
	
	 return string;
	
}


/** main function */

int main()
{  

int size = 0;
printf("Enter the Size of string = ");
scanf("%d",&size);

char string[size];

printf("\nEnter the string = ");
scanf("%s",string);

printf("\nReverse of %s is %s\n",string, reverseString(string,size));

 return 0;
 
}
