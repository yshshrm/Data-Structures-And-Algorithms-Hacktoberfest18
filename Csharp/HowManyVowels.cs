using System;

using System.Linq;


namespace CodewarsAlgorithms
{


    public static class Kata

    {

        public static int GetVowelCount(string str)

        {

            int vowelCount = 0;



            // Your code here

            char[] letters = str.ToCharArray();



            foreach (char c in letters)

            {

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')

                {

                    vowelCount++;

                }

            }



            return vowelCount;

        }

    }
}