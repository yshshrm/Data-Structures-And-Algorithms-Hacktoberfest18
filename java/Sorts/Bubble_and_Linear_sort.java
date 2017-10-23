import java.util.*;

class Bubble_and_Linear_sort
{
static int[] a=new int[100];
static int numberOfElements;
public static void main(String args[])
{

Scanner sc=new Scanner(System.in);
System.out.println("Enter the number of elements:");
 numberOfElements=sc.nextInt();
for(int i=0; i<numberOfElements; i++)
{
	a[i]=sc.nextInt();
}
System.out.println("Select the Type of Sorting you prefer:");
System.out.println("1.Linear Sort");
System.out.println("2.Binary Sort");
int choice=sc.nextInt();
switch(choice)
{
case 1:System.out.println("Linear sorting technique used");
	linearSort();
	display();
	break;
case 2:System.out.println("Bubble Sortint technique used:");
	bubbleSort();
	display();
	break;

}
}
public static void linearSort()
{
int temp;
for(int i=0;i<numberOfElements; i++)
{
	for(int j=i;j<numberOfElements;j++)
	{
		if(a[i]>a[j])
		{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
}
}
public static void bubbleSort()
{
int temp;
for(int i=0; i<numberOfElements; i++)
{
	for(int j=0;j<numberOfElements;j++)
	{
		if(a[j]>a[j+1])
		{
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
	}
}
}
public static void display()
{
for(int i=0;i<numberOfElements;i++)
	System.out.println(a[i]);
}
}
