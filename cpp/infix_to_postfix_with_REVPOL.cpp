//infix to postfix conversion using REVPOL algorithm.
//time complexity of these is O(n^2).
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *link;
};

struct Node *top;

void push(char data)
{

    struct Node *temp;
    temp = new Node();
    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }

    temp->data = data;

    temp->link = top;

    top = temp;
}
char pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
        return NULL;
    }
    else
    {

        temp = top;

        top = top->link;

        temp->link = NULL;
        char c = temp->data;
        free(temp);
        return c;
    }
}
int in_pre(char c)
{
    //giveng priorites to all charecters which are in input string.
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '^')
    {
        return 6;
    }
    else if (c == '(')
    {
        return 9;
    }
    else if (c == ')')
    {
        return 0;
    }
    else
    {
        return 7;
    }
}
int stk_pre(char c)
{
    //giving priorites to all other characters which are present in stack.
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/')
    {
        return 4;
    }
    else if (c == '^')
    {
        return 5;
    }
    else if (c == '(')
    {
        return 0;
    }
    else
    {
        return 8;
    }
}
int count_rank(char c)
{
    //counting rank of output postfix expression.
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string s, post = "";
    cin >> s;
    vector<char> v;
    int tp = 0, rank1 = 0;
    //initialize stack with '('.
    v.push_back('(');
    char ch1;
    bool flag1 = true;
    int i = 0;
    while (s[i])
    {
        while (in_pre(s[i]) < stk_pre(v[tp]))
        {
            ch1 = v[tp];
            post += ch1;
            rank1 += count_rank(ch1);
            v.pop_back();
            tp--;
            if (rank1 < 1)
            {
                cout << "invalid infix" << endl;
                flag1 = false;
                break;
            }
        }
        if (flag1 && (stk_pre(v[tp]) != in_pre(s[i])))
        {
            v.push_back(s[i]);
            tp++;
        }
        else if (flag1)
        {
            v.pop_back();
            tp--;
        }
        i++;
    }
    if (rank1 == 1 && tp == -1)
    {
        cout << post << endl;
    }
    return 0;
}
