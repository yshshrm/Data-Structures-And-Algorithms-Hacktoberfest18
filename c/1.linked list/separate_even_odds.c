#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

// Let the list be 1-2-3-4-5-6-7-8-9-10-11

int separate_even_odds(struct node* head){
	struct node *even_list, *odd_list, *even_end, *odd_end, *temp;
	even_list = odd_list = even_end = odd_end = NULL;
	temp = head;
	if(head == NULL)
		return -1;
	else{
		while(temp){
			if(temp -> key % 2 == 0){
				if(even_list == NULL)
					even_list = even_end = temp;
				else{
					even_end -> next = temp;
					even_end = temp;	
				}
			}
			else{
				if(odd_list == NULL)
					odd_list = odd_end = temp;
				else{ 
					odd_end -> next = temp;
					odd_end = temp;	
				}
			}
			temp = temp -> next;
		}	
	}
	even_end -> next = odd_list;
	display(even_list);
	return 1;
}

int main(){

	struct node *head;

	head = createnode(1);
	head -> next = createnode(2);
	head -> next -> next = createnode(3);
	head -> next -> next -> next = createnode(4);
	head -> next -> next -> next -> next = createnode(5);
	head -> next -> next -> next -> next -> next = createnode(6);
	head -> next -> next -> next -> next -> next -> next = createnode(7); 
	head -> next -> next -> next -> next -> next -> next -> next = createnode(8);
	head -> next -> next -> next -> next -> next -> next -> next -> next = createnode(9);
	head -> next -> next -> next -> next -> next -> next -> next -> next -> next = createnode(10);
	head -> next -> next -> next -> next -> next -> next -> next -> next -> next -> next = createnode(11);

	if(separate_even_odds(head) == -1) printf("\nNULL node");
	free(head);
	return 0;	
}