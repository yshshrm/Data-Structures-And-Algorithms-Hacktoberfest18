#include <iostream>
#include <cstdlib>


using namespace std;


struct node
{
   int data;
   node *next;
};

node *top=NULL;


void insert_front (int idata)
{
   node* temp = new node;
   temp->data = idata;
   temp->next=NULL;
   if(top==NULL)
   {
      top=temp;
   }
   else
   {
       temp->next = top;
       top = temp;
   }
}

void display() {
   node* ptr;
   ptr = top;
   while (ptr != NULL)
   {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
void insert_end(int idata)
{
    node *temp = new node;
	temp->data = idata;
	temp->next =NULL;
	node *ptr =top;
	while(ptr->next != NULL)
    {
		ptr = ptr->next;
	}
	ptr->next = temp;
}

void count()
{
	int count = 0;
	node *ptr;
	ptr = top;
	while(ptr != NULL)
    {
		count = count + 1;
		ptr = ptr->next;
	}
	cout<<"\n"<<"Total Length is : "<<count;
}

void search(int data)
{

	int pos = 1;
	node *ptr;
	ptr = top;
	while(ptr != NULL && ptr->data != data)
    {
		pos = pos + 1;
		ptr = ptr->next;
	}

	if(ptr != NULL)
		cout<<"\n"<<"Found at : "<<pos<<" and memory address"<<&ptr;
    else
		cout<<"\n"<<"Not Found!!!";
}

int delete_front()
{
	node* ptr = top;
	if(ptr==NULL)
        return -1;
	top=ptr->next;
	delete ptr;
}

node* delete_last()
{
    if (top== NULL)
        return NULL;

    if (top->next == NULL)
    {
        delete top;
        return NULL;
    }
    node* second_last = top;
    while (second_last->next->next != NULL)
        second_last = second_last->next;

    second_last->next = NULL;
    return top;
}

int delete_at(int pos)
{
	int i=1;
	node *ptr = top;
	node *prev;

	while(i !=pos )
    {
        if(ptr->next==NULL)
        {
            cout<<"not found";
        }
		prev = ptr;
		ptr = ptr->next;
	    i++;
	}
	prev->next = ptr->next;
	delete ptr;
	cout<<"\nSuccesfully Deleted at Position : "<<pos<<"\n ";
}
int main() {
   insert_front(3);
   insert_front(1);
   insert_front(7);
   insert_front(2);
   insert_end(13);
   insert_front(9);
   insert_end(11);

   //delete_first();

   cout<<"The linked list is: ";
   display();
   count();
   //delete_at(3);
   //search(7);
   delete_last();
   cout<<"\nThe linked list is: ";
   display();


   return 0;
}
