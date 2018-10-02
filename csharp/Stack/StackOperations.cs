using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class StackOperations
    {
        public float doubleNumberAverage(Stack<int> st)
        {
            Stack<int> reverse = new Stack<int>(st.size());
            float total = 0, count = 0;

            while (!st.isEmpty())
            {
                int temp = st.pop();
                reverse.push(temp);

                if (temp % 2 == 0)
                {
                    total += temp;
                    count++;
                }
            }

            while (!reverse.isEmpty())
                st.push(reverse.pop());

            if (count != 0)
                return total / count;
            else
                return default(float);
        }
    }
}
