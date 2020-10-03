#include "LinkedList.h"

int main()
{
	LinkedList list;
  // inserting values in LiskedList
	list.insert(12);
	list.insert(23);
	list.insert(53);
	list.insert(44);
	list.insert(66);
	list.insert(49);
  // Printing all values
	list.print();
  // Intserting after a perticluar value
	list.insertAfter(list.search(23), 55);
	list.print(); //printing all values
	list.remove(49); // removing 49 from list
	list.print(); //printing all values
	list.remove(12); // removing 12 from list
	list.print(); //printing all values
	return 0;
}
