/*
Author: dvlpsh
DEscription: Contains all functionalities of a linked list on C along with its insertion sort as well as physically reversing a linkedlist.
*/

#include <stdio.h>
#include <stdlib.h>

#define item int

typedef struct ll
{
	item data;
	struct ll *next;
}node;


node *getNode()
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	return temp;
}

node *search(node *head,item z)
{
	if(head == NULL)
		return NULL;
		
	else
	{
		while(head!= NULL)
		{
			if(head->data == z)
				return head;
			head = head->next;
		}
		
	}
	
}


void insertbetw(node *p, item v)// add after
{
	node *temp;
	temp = getNode();
	temp->data = v;
	temp->next = p->next;
	p->next = temp;
}


node *searchbypos(node *head, int pos)
{
	int c=1;
	//node *temp;
	//temp = *head;
	if(pos<1)
		return NULL; //postion is invalid 
		
	while(head!= NULL)
	{
		if(c == pos)
			return head;
		c++;
		head = head->next;
	}
	
	if(head == NULL && c!=pos)
		return NULL;// pos>length of linked list and thus invalid.
}


void addbeg(node **head,item v)
{
	node *temp;
	temp = getNode();
	temp->data = v;
	temp->next = *head;
	*head = temp;
}


void append(node **head, item v)
{
	node *temp;
	temp = getNode();
	temp->data = v;
	temp->next = NULL;
	
	if(*head == NULL)
		*head = temp;
		
	else
	{
		node *temp2;
		temp2 = *head;
		while(temp2->next!= NULL)
			temp2 =temp2->next;
			
		temp2->next = temp;
	}

}


void del(node *p)
{
	node *temp;
	temp = p->next;
	p->next = p->next->next;
	free(temp);
}

void delbeg(node **head)
{
	node *temp;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void delend(node **head,int count)
{
	node *temp;
	if((*head)->next == NULL) //last and only node
	{
		temp = *head;
		*head = (*head)->next; //points to null.
		free(temp);
	}
	
	else
	{
		temp = searchbypos(*head, count-1); //finding the last node
		del(temp);
	}
}


void dellist(node **head)
{
	node *temp;
	while(*head!= NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void printlist(node *head)
{
	node *temp;
	
	printf("The list is: ");
	
	for(temp=head; temp!=NULL; temp=temp->next)
		printf("%d ",temp->data);
		
	printf("\n");
}

void sort(node ** head) //sorting the linked list.
{
	node *p,*q,*a,*b;
	
	for(a= *head, b= (*head)->next; b!= NULL;)
	{
		for(p= NULL,q = *head; (((b->data) > (q->data)) && q!=b); p=q, q= q->next)
			;
	
		if(q == b)
		{
			a = a->next;
			b = b->next;
		}
		
		else
		{
			a->next = b->next;
			b->next = q;
			
			if(p == NULL)
				*head = b; //insert at the 0th position
				
			else
				p->next = b;
			
			b = a->next;
		}		
	}
}


void showrev(node **head)
{
	//physically reverse
	
	node *p,*c,*s;
	p=NULL;
	c = *head;
	
	if(*head == NULL) //list is empty
		return ;//list is empty and cannot reverse.
		
		
	else //list is not empty so can be physically reversed.
	{
		do
		{
			s = c->next;
			c->next = p;
			p = c;
			c = s;
			
		}while(c!=NULL);
	
		*head = p;
	}
	

}


int main()
{
	node *head = NULL;
	
	int ch,num,i,pos=1,val,no; static int count=0;
	node *res;
	
	do
	{
	
		printf("Menu.\n1.Insert at the beginning\n2.Insert at the end.\n3.Insert after a given node.\n4.Insert at a given position.\n5.Delete from the beginning.\n6.Delete from the end.\n7.Delete from Between.\n8.Sort the list.\n9.Reverse the list.\n Press -1 to exit.\n\n");
		scanf("%d", &ch);
	
		switch(ch)
		{
			case 1:
				printf("Enter the item to enter into the beginning of the list: ");
				scanf("%d", &num);
				addbeg(&head,num);
				++count; //maintains the size of the list.
				printlist(head);
				break;
			case 2:
				if(head == NULL)
				{
					printf("List is empty, so element will be inserted at the beginning: ");
					printf("Enter the item to enter into the end of the list: ");
					scanf("%d", &num);
					addbeg(&head,num);
					++count;
					printlist(head);
					break;
				}
				else
				{
					printf("Enter the item to enter into the end of the list: ");
					scanf("%d", &num);
					append(&head,num);
					++count;
					printlist(head);
					break;
				}
			case 3:
				if(head == NULL)
				{
					printf("List is Empty.\n");
					break;
				}
				
				else
				{
					printf("Enter the node after which you want to enter an element into the list: ");
					scanf("%d", &num);
					res = search(head,num);
					if(res!= NULL)
					{
						printf("Enter the value you want to insert: ");
						scanf("%d",&no);
						insertbetw(res,no);
						++count;
						printlist(head);
						break;
					}
				
					else
					{
						printf("Node not found.\n");
						break;					
					}
				
					break;
				}
			case 4:
				if(head == NULL && pos!=1)
				{
					printf("List is Empty. And invalid position.\n");
					break;
				}
				
				
				else //list is not empty
				{
					printf("Enter the position where you want to insert: ");//taking it here as we might want to add an element to a empty list as the first element.
					scanf("%d", &pos);
				
					if(pos>count+1 || pos<1) // count+1 means we can insert at last position also. So we call append function
					{
						printf("Invalid position.\n");
						pos =1;
						break;
					}
					
					else //position is valid. 
					{
						printf("Enter the value to be inserted: ");
						scanf("%d", &num);
					
						if(pos == count+1) //insert at last position
						{
							append(&head,num);
							++count;
							printlist(head);
							break;
						}
					
						else if(pos == 1)//insert at first position.
						{
							addbeg(&head,num);
							++count; //maintains the size of the list.
							printlist(head);
						}
					
						else //any other position
						{
							res = searchbypos(head, pos-1);
				
							if(res!= NULL)
							{
								insertbetw(res,num);
								++count;
								printlist(head);
								break;
							}
							else
							{
								printf("Invalid postion.\n");
								break;
							}
					
							break;
						}
					}
				
					break;
				}	
				
			case 5:
				if(head!= NULL)
				{
					printf("Deleting the first element.\n");
					delbeg(&head);
					--count;
					if(head == NULL)
						printf("List is Empty.\n");
						
					else
						printlist(head);
					break;
				}
				else //list is already empty
				{
					printf("List is empty. Cannot delete items.\n");
					break;
				}
			case 6:
				if(head!= NULL) //list not empty
				{
					delend(&head,count);
					--count;
					printf("Deleting the last element.\n");
					if(head == NULL) //deleted the last and the only element.
					{
						printf("List Empty.\n");
						break;
					}
					else
					{
						printlist(head);
						break;
					}
				}
				
				else //list is already empty
				{
					printf("List is empty.Cannot delete any more Elements.\n");
					break;
				}
				
			case 7:
				if(head == NULL)
				{
					printf("LIst is Empty.\n");
					break;
				}
				
				else
				{
					printf("Enter the position to delete from: ");
					scanf("%d", &pos);
					if(pos == count && head!= NULL) //deleting from the end and list is not empty
					{
						delend(&head,count);
						--count;
						printf("Deleting the last element.\n");
						if(head == NULL) //deleted the last and the only element.
						{
							printf("List Empty.");
							break;
						}
						else
						{
							printlist(head);
							break;
						}
					}
				
					else if(pos == count && head == NULL) //list is empty
					{
						printf("List is empty.Cannot delete any more Elements.\n");
						break;
					}
				
					else if(pos == 1 && head!= NULL) // deleting from the beginning of the list and the list is not empty
					{
						printf("Deleting the first element.\n");
						delbeg(&head);
						--count;
						printlist(head);
						break;
					}
				
					else if(pos == 1 && head == NULL) //list is empty and cannot delete
					{
						printf("List is empty. Cannot delete items.\n");
						break;
					}
				
					else //in position other than first and last
					{	
						if(pos>count || pos <1)
						{
							printf("Invalid position.\n");
							break;
						}
					
						else
						{		
							res = searchbypos(head,pos-1);
				
							if(res!= NULL)
							{
								del(res);
								--count;
								printlist(head);
								break;
							}
				
							else
							{
								printf("Invalid position.");
								break;
							}
						}
					
						break;
					}
				
					break;
				}
				
				break;
				
				case 8:
					if(head == NULL)//list is empty
					{
						printf("The list is Empty.Cannot sort list.\n");
						break;
					}
					
					else 
					{
						//list is not empty.So we can sort the list.
						sort(&head);
						printlist(head);
					}
					
					break;
					
				case 9:
					if(head == NULL)//list empty
					{
						printf("List is empty.Cannot reverse list.\n");
						break;
					}
					
					else //list not empty so can be reversed.
					{
						showrev(&head);
						printlist(head);
						break;
					}
					
		}
			
	} while(ch!=-1);
	
	
	
	return 0;
}








