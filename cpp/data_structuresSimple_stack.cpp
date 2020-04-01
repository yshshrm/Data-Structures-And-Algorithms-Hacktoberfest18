#include <iostream>

using namespace std;

class Stack
{
private:
    int *p;
    int top,length;

public:
    Stack(int = 0);
    ~Stack();

    void push(int);
    int pop();
    void display();
};

Stack::Stack(int size)
{
    top=-1;
    length=size;
    if(size == 0)
        p = 0;
    else
        p=new int[length];
}

Stack::~Stack()
{
    if(p!=0)
        delete [] p;
}

void Stack::push(int elem)
{
    if(p == 0)                //If the stack size is zero, allow user to mention it at runtime
    {
        cout<<"Stack of zero size"<<endl;
        cout<<"Enter a size for stack : ";
        cin >> length;
        p=new int[length];
    }
    if(top==(length-1))     //If the top reaches to the maximum stack size
    {
        cout<<"\nCannot push "<<elem<<", Stack full"<<endl;
        return;
    }
    else
    {
        top++;
        p[top]=elem;
    }
}
int Stack::pop()
{
    if(p==0 || top==-1)
    {
        cout<<"Stack empty!";
        return -1;
    }
    int ret=p[top];
    top--;
    return ret;
}

void Stack::display()
{
    for(int i = 0; i <= top; i++)
        cout<<p[i]<<" ";
    cout<<endl;
}

int main()
{
    Stack s1;             //We are creating a stack of size 'zero'
    s1.push(1);
    s1.display();
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
}
