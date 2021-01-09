# include<stdio.h>
# include<stdlib.h>
# include<string.h>

// swapping a and b
void swap(char *a , char *b)
{ 
char temp = '\0';
temp =*a;
*a = *b;
*b= temp;
return ;

}

// Reverse the string 
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
		

	int i=0,j=size-1;
	
	for(;i<j;i++,j--)
	{ 
	 swap(&string[i],&string[j]);	  
	
	}
	
	 return string;
	
}

// converting Decimal number to hexa decimal  string
char * decimaltoHex(unsigned int  num){
    
    if(num==0)
        return "0";
    char *ch= (char *)malloc(100000*sizeof(char));
    
    int i=0;
    
while(num)
{ 
if(num%16<10)
    ch[i]= (char)(48+num%16);
 else
     ch[i] = (char)(97 + num%16-10);
 
 num /=16;        
    ++i;    
    
}

ch[i] = '\0';

return reverseString(ch,i);

}


int main()
{ 

int decimal;

printf("Enter the number = ");

scanf("%d",&decimal);

printf("\nHexadecimal of %d is %s ",decimal,decimaltoHex(decimal));

return 0;
     
}