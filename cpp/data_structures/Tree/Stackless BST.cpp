// Stackless BST.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

template <class T>
class SortedStacklessBST;

template <class T>
class Node
{
private:
	T value;
	Node<T> *nextInOrder;
	Node<T> *leftChild;
	Node<T> *rightChild;

public:
	Node ()
	{
		value = NULL;
		leftChild = rightChild = nullptr;
	}
	Node (T Value,Node<T> *NextInOrder = nullptr,Node<T>* leftchild = nullptr,Node<T>* rightchild = nullptr)
	{
		value = Value;
		leftChild = leftchild;
		rightChild = rightchild;
		nextInOrder = NextInOrder;
	}
	~Node ()
	{
		nextInOrder = leftChild = rightChild = nullptr;
	}
	friend class SortedStacklessBST<T>;
};

template <class T>
class SortedStacklessBST
{
private:
	Node<T> *root;
	bool IsSuccessor;
	int numberOfNodes;
	T max (const T &a,const T &b)	const
	{
		if (a>b)
			return a;
		return b;
	}
	T FindPredAndDelete (Node<T>* & node)
	{
		Node<T>** prev = &node;
		Node<T>** curr = &node;
		int i = 0;
		for (; (*curr)->rightChild!=nullptr; i++)
		{
			curr = &(*curr)->rightChild;
			if (i!=0)
				(prev) = &(*prev)->rightChild;
		}
		T Data = (*curr)->value;
		Node<T>* tmp = nullptr;
		if ((*prev)->rightChild)
			tmp = (*prev)->rightChild->leftChild;
		else
		{
			tmp = (*prev)->leftChild;
			//	tmp->nextInOrder = (*curr);
		}
		(*curr)->nextInOrder = this->root->nextInOrder;
		if (tmp)
			tmp->nextInOrder = (*curr);
		delete *curr;
		(*curr) = nullptr;
		(*curr) = tmp;
		return Data;
	}
	bool remove (Node<T>*&_root,const T& key,Node<T>*lastRight,Node<T>*lastLeft,bool &flag1,bool &flag2)
	{
		if (_root==nullptr)
			return 0;
		else if (_root->value>key)
		{
			flag1 = true;
			if (_root)
			{
				if (_root->leftChild)
				{
					if (_root->leftChild->value!=key)
						lastLeft = &(*_root->leftChild);
					else
					{
						lastLeft = &(*_root);
						lastLeft->nextInOrder = &(*_root->leftChild->nextInOrder);
					}
				}
				remove (_root->leftChild,key,lastRight,lastLeft,flag1,flag2);
			}
		}
		else if (_root->value<key)
		{
			flag2 = true;
			if (_root)
			{
				if (_root->rightChild)
				{
					if (_root->rightChild->value!=key)
						lastRight = &(*_root->rightChild);
					else
					{
						lastRight = &(*_root);
						lastRight->nextInOrder = &(*_root->rightChild->nextInOrder);
					}
				}
				remove (_root->rightChild,key,lastRight,lastLeft,flag1,flag2);
			}
		}
		else
		{
			Node<T>* temp = _root;
			if (_root->leftChild==_root->rightChild)
			{
				delete _root;
				_root = nullptr;
				flag1 = flag2 = false;
			}
			else if (_root->leftChild==nullptr)
			{
				_root = _root->rightChild;
				delete temp;
				temp = nullptr;

				flag1 = false;
			}
			else if (_root->rightChild==nullptr)
			{
				_root = _root->leftChild;
				delete temp;
				temp = nullptr;
				flag2 = false;
			}
			else
				_root->value = FindPredAndDelete (_root->leftChild);
			if (lastLeft && flag1)
			{
				Node<T>** tmp = &(FindPred (_root->leftChild));
				if (*tmp)
					(*tmp)->nextInOrder = lastLeft;
			}
			if (lastRight && flag2)
			{
				Node<T>** tmp = &(FindPred (_root->leftChild));
				if (*tmp)
					(*tmp)->nextInOrder = lastRight;
			}
			return 1;
		}
		return 1;
	}
	Node<T>*& FindPred (Node<T>* _root)
	{
		Node<T>** temp = &_root;
		if ((*temp)!=nullptr)
		{
			for (; (*temp)->rightChild!=nullptr; temp = &(*temp)->rightChild);
		}
		return (*temp);
	}
	void Print (Node<T>* next,bool flag,T low,T high)
	{
		if (next==nullptr)
			return;
		if (!flag||((next->value>=low)&&(next->value<=high)))
		{
			cout<<next->value<<"\t";
		}
		Print (next->nextInOrder,flag,low,high);
	}
	void isLeafBalance (Node<T>* ptr,int& height,int &max,int &min)
	{
		if (ptr==nullptr)
			return;
		else if (ptr->leftChild==ptr->rightChild)
		{
			if (min==0&&max==0)
			{
				max = height;
				min = height;
			}
			if (min>height)
				min = height;
			if (max<height)
				max = height;
			return;
		}
		height++;
		isLeafBalance (ptr->leftChild,height,max,min);
		isLeafBalance (ptr->rightChild,height,max,min);
		height--;
	}
	void CopyConstructor (Node<T>*& _root,Node<T>* Obj)
	{
		if (Obj==nullptr)
			return;
		this->insert (Obj->value);
		CopyConstructor (_root->leftChild,Obj->leftChild);
		CopyConstructor (_root->rightChild,Obj->rightChild);
	}
	/*void DestroyRecursive (Node<T>*& _root)
	{
	if (_root)
	{
	DestroyRecursive (_root->leftChild);
	DestroyRecursive (_root->rightChild);
	delete _root;
	_root = nullptr;
	}
	}*/
	void ReverseOrder (Node<T>* node,Node<T>* PreviousNode = nullptr)
	{
		if (node==nullptr)
			return;
		if (node->nextInOrder!=nullptr)
			ReverseOrder (node->nextInOrder,node);
		if (node)
			node->nextInOrder = PreviousNode;
		if (PreviousNode)
			PreviousNode->nextInOrder = nullptr;
	}
public:
	SortedStacklessBST ()
	{
		root = nullptr;
		IsSuccessor = true;
		numberOfNodes = 0;
	}
	SortedStacklessBST (const SortedStacklessBST <T>*&Obj)
	{
		IsSuccessor = Obj->IsSuccessor;
		CopyConstructor (root,Obj->root);
		numberOfNodes = Obj->numberOfNodes;
	}
	SortedStacklessBST<T>& operator = (const SortedStacklessBST<T> & Obj)
	{
		if (root!=nullptr)
			this->~SortedStacklessBST<T> ();
		CopyConstructor (root,Obj.root);
		return *this;
	}
	bool insert (const T value)
	{
		if (root==nullptr)
		{
			root = new Node<T> (value);
			numberOfNodes++;
		}
		else
		{
			bool flag = true;
			Node<T>** temp = &root;
			Node<T>* ptr1 = root;
			Node<T>* ptr2 = nullptr;
			Node<T>* ptr3 = nullptr;
			Node<T>* order = nullptr;
			if (IsSuccessor)
			{
				for (; (*temp)!=nullptr;)
				{
					if ((*temp)->value==value)
					{
						flag = false;
						break;
					}
					else if ((*temp)->value>value)
					{
						temp = &(*temp)->leftChild;
						if ((*temp))
						{
							ptr2 = ptr1;
							ptr1 = (*temp);
						}
						else
							order = ptr1;
					}
					else
					{
						ptr3 = (*temp);
						temp = &(*temp)->rightChild;
						if ((*temp))
						{
							ptr1 = (*temp);
						}
						else
							order = ptr2;
					}
				}
			}
			else
			{
				for (; (*temp)!=nullptr;)
				{
					if ((*temp)->value==value)
					{
						flag = false;
						break;
					}
					else if ((*temp)->value>value)
					{
						ptr3 = (*temp);
						temp = &(*temp)->leftChild;
						if ((*temp))
						{
							ptr1 = (*temp);
						}
						else
							order = ptr2;
					}
					else
					{
						temp = &(*temp)->rightChild;
						if ((*temp))
						{
							ptr2 = ptr1;
							ptr1 = (*temp);
						}
						else
							order = ptr1;
					}
				}
			}
			if (flag)
			{
				(*temp) = new Node<T> (value,order);
				if (ptr3)
					ptr3->nextInOrder = (*temp);
				numberOfNodes++;
			}
			return flag;
		}
		return 1;
	}
	bool search (const T value)
	{
		bool found = false;
		Node<T>* temp = root;
		for (; temp!=nullptr;)
		{
			if (temp->value==value)
			{
				found = true;
				break;
			}
			else if (temp->value>value)
				temp = temp->leftChild;
			else
				temp = temp->rightChild;
		}
		return found;

	}
	void Print (bool flag = NULL,T low = NULL,T high = NULL) // if flag is set then conditions will be check otherwise it just print the whole tree
	{
		if (root)
		{
			Node<T>* temp = root;
			if (IsSuccessor)
			for (; temp->leftChild!=nullptr; temp = temp->leftChild);
			else
			for (; temp->rightChild!=nullptr; temp = temp->rightChild);
			Print (temp,flag,low,high);
		}
	}
	bool isLeafBalance ()
	{
		int a = 0,b = 0,c = 0;
		isLeafBalance (root,a,b,c);
		return b==c;
	}
	bool remove (const T& value)
	{
		Node<T>* lastRight = nullptr,*lastLeft = nullptr;
		bool flag1 = true,flag2 = true,IsRemove = true,InOrder = true;
		if (!IsSuccessor)
		{
			InOrder = false;
			ReverseOrder ();
		}
		IsRemove = remove (root,value,lastLeft,lastLeft,flag1,flag2);
		if (!InOrder)
		{
			ReverseOrder ();
		}
		if (IsRemove)
			numberOfNodes--;
		return IsRemove;
	}
	void ReverseOrder ()
	{
		Node<T>* temp = root;
		if (IsSuccessor)
		for (; temp->leftChild!=nullptr; temp = temp->leftChild);
		else
		for (; temp->rightChild!=nullptr; temp = temp->rightChild);
		ReverseOrder (temp);
		(IsSuccessor) ? IsSuccessor = false : IsSuccessor = true;
	}
	bool getSuccessor () const
	{
		return IsSuccessor;
	}
	int getNumberOfNodes () const
	{
		return numberOfNodes;
	}
	~SortedStacklessBST ()
	{
		Node<T>* temp = root;
		if (IsSuccessor)
		for (; temp->leftChild!=nullptr; temp = temp->leftChild);
		else
		for (; temp->rightChild!=nullptr; temp = temp->rightChild);
		while (root!=nullptr)
		{
			root = temp->nextInOrder;
			delete temp;
			temp = nullptr;
			temp = root;
		}
		root = nullptr;
	}
};


char* BoolMessage (int i)
{
	if (i==1)
		return "Yes";
	else
		return "No";
}

template<typename T>
void TopBoard (SortedStacklessBST<T>* Obj)
{

	cout<<"\t\tSameer Sorted Stackless Binary Search Tree v.1.1\n\n\n";
	cout<<"Number of nodes in BST : "<<Obj->getNumberOfNodes ()<<"\t\t\t\t"<<"IsSuccessor : "
		<<BoolMessage (Obj->getSuccessor ())<<"\nLead Nodes Balanced : "<<BoolMessage (Obj->isLeafBalance ());
	cout<<"\n\n________________________________________________________________________________\n\n";
}
void Driver ()
{
	SortedStacklessBST<int>*a = new SortedStacklessBST<int>;
	while (1)
	{
		int choice = 0;
		int value;
		system ("CLS");
		TopBoard (a);
		cout<<"1) Insert Node\n2) Search Node\n3) Print Tree\n4) Print Tree in given range\n5) Remove Node\n6) Reverse Tree\n\n0) Exit\n\n\t\t\tInput Your Choice : ";
		cin>>choice;
		if (choice==0)
			break;
		else if (choice==1)
		{
			cout<<"\nInput the value : ";
			cin>>value;
			if (!a->insert (value))
				cout<<"Given value cannot be inserted because it is already present!\n";
			else
				cout<<endl<<value<<" is inserted in BST Successfully!\n";
		}
		else if (choice==2)
		{
			cout<<"\nInput the value of Node that you want to search : ";
			cin>>value;
			if (!a->search (value))
				cout<<"Given node is not present!\n";
			else
				cout<<endl<<value<<" is in the BST!\n";
		}
		else if (choice==3||choice==4)
		{
			if (choice==4)
			{
				int min = 0,max = 0;
				cout<<"\nInput the lower Boundary : ";
				cin>>min;
				cout<<"\nInput the higher Boundary : ";
				cin>>max;
				a->Print (1,min,max);
			}
			else
				a->Print (0,0,0);
		}
		else if (choice==5)
		{
			cout<<"\nInput the value of Node that you want to remove : ";
			cin>>value;
			if (a->remove (value))
				cout<<"Given node is removed successfully!\n";
			else
				cout<<endl<<value<<" is not present in the BST!\n";
		}
		else if (choice==6)
		{
			cout<<"\nTree has been reversed hopefully!:)";
			a->ReverseOrder ();
		}
		else
		{
			cout<<"\n\nInvalid Choice!!!\nTry Again\n";
		}
		cout<<"\n\n\t\t";
		system ("pause");
	}
}


int main ()
{

	Driver ();
	system ("pause");
	return 0;
}