using System;

class Palindrome
{
    static bool isPalindrome(string input)
    {
        if (input.Length == 0) return false;
        if (input.Length == 1) return true;

        for(int i = 0; i < input.Length/2; i++)
        {
            if(char.ToLower(input[i]) != char.ToLower(input[input.Length-1-i]))
            {
                return false;
            }
        }
        return true;
    }

    // Test
    static void Main(string[] args)
    {
        Console.WriteLine("Test Palindrome:");
        Console.WriteLine("Fun :" + isPalindrome("Fun"));
        Console.WriteLine("Anna :" + isPalindrome("Anna"));
        Console.WriteLine("Anhna :" + isPalindrome("Anhna"));
        Console.WriteLine("Test :" + isPalindrome("Test"));
        Console.ReadKey();
    }
}
