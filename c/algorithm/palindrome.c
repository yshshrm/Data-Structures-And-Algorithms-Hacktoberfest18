#include <stdio.h>
#include <string.h>
int main()
{
	printf("enter a string : ");
	char arr[100];
	int flag=1;
	scanf("%[^\n]s",arr);
	int j=strlen(arr)-1;
	for(int i=0;i<=strlen(arr)/2;i++,j--)
	{
		if(arr[i]==arr[j])
			flag=0;
		else
		{
			flag=1;
			break;
		}
	}
	if(!flag)
		printf("palindrome\n");
	else
		printf("not palindrome\n");
	return 0;
}
