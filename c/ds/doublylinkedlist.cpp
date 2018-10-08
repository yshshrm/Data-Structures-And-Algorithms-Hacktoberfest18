#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

struct node
{

	int id ;
    char name[20];
    struct node*prev;
    struct node*next;
    

};


node*temp,*start=NULL,*last=NULL;


void creation();
void deletion();
void display();


int main()
{
	int decision;
	int ch;
	ch=1;
 while(ch==1)
{
	
	printf(" \n 1.CREATE A NEW CONSUMER RECORD \n 2.DELETE A RECORD \n 3.DISPLAY \n  4.EXIT \n");
	
	printf("\n ENTER YOUR CHOICE ");
	scanf("%d", &decision);
	
	
	switch(decision)
	{
		
		case 1 : creation();
		          break;
		          
		          
		case 2 :   deletion();
					break;
					
					
		case 3 :  display();
					break;
					
					
		case 4 : exit(0);
		
		
	}

}
	return 0;
}


void creation()
{   

    int ch;
    ch=1;
	
 while(ch==1)
	
 {
	 	
	
	temp= (node*)malloc(sizeof(node));
	
	printf(" ENTER THE CONSUMER ID : ");
	scanf("%d",&temp->id);
	
	printf(" ENTER THE CONSUMER NAME : ");
	scanf("%s",&temp->name);
	
	
    if(start==NULL)
    {
    	temp->prev=NULL;
    	temp->next=NULL;
    	start=last=temp;
	}


    else
	{
		 temp->next=start;
		 start->prev=temp;
		 
		 start=temp;
		 
		 
	}

   printf(" WANT TO ENTER MORE (0/1) : ");
   scanf("%d",&ch);

}

}

void deletion()
{
	
	if(start==NULL)
	{
		printf(" NO DATA TO DELETE");
		
		
	}
	
	else
   {
		
  	 temp=start;
     node*temp2;
     
     while(temp->next!=NULL)
     {
     	temp2=temp;
     	
        temp=temp->next;
     	
     	
	 }
	    
    temp2->next=NULL;	

  
  }
	
		
}

void display()
{
	temp=start;
	
	while(temp!=NULL)
	{
		
	    printf(" C.NAME : %s  C.ID : %d  -->", temp->name,temp->id)	;
	    
	    temp=temp->next;
		
	}

	printf("NULL \n");
	
}




































