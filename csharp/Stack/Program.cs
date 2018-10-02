using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            StackOperations so = new StackOperations();
            Stack<int> st1 = new Stack<int>(5);

            st1.push(10);
            st1.push(15);
            st1.push(25);
            st1.push(35);
            st1.push(45);
            st1.display();
        }
    }
}
