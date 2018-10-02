using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Stack<T> where T : IComparable
    {
        T[] values;
        int top;

        public Stack(int size)
        {
            values = new T[size];
            top = 0;
        }

        public int size()
        {
            return values.Length;
        }

        public void clear()
        {
            top = 0;
        }

        public bool isEmpty()
        {
            if (top == 0)
                return true;
            else
                return false;
        }

        public bool isFull()
        {
            if (top == size())
                return true;
            else
                return false;
        }

        public void push(T value)
        {
            if (!isFull())
                values[top++] = value;
        }

        public T pop()
        {
            if (!isEmpty())
                return values[top--];
            return default(T);
        }
        
        public T peek()
        {
            if (!isEmpty())
                return values[top];
            return default(T);
        }

        public void search(T wanted)
        {
            Stack<T> reverse = new Stack<T>(size());
            bool flag = false;

            while (!isEmpty())
            {
                T temp = pop();
                reverse.push(temp);

                if (wanted.CompareTo(temp) == 0)
                {
                    flag = true;
                    break;
                }
            }

            while (!reverse.isEmpty())
                push(reverse.pop());

            if (flag)
                Console.WriteLine("Found!");
            else
                Console.WriteLine("Not found!");
        }

        public bool isPalindrome(string s)
        {
            Stack<string> st = new Stack<string>(s.Length);

            for (int i = 0; i < s.Length; i++)
                st.push(s[i].ToString());

            for (int i = 0; i < s.Length / 2; i++)
                if (st.pop() != s[i].ToString())
                    return false;
            return true;
        }

        public void display()
        {
            for(int i = top - 1; i >= 0; i--)
                Console.Write(values[i] + "  ");
            Console.WriteLine();
        }
    }
}
