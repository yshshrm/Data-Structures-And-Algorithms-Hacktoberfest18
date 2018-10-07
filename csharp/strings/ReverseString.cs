using System;

class ReverseString
{
    public static string Reverse(string input)
    {
        if(string.IsNullOrEmpty(input)) return "";
        char[] output = new char[input.Length];
        for(int i = 0;i < input.Length; i++)
        {
            output[i] = input[input.Length - 1 - i];
        }
        return new string(output);
    }

    //Tests
    static void Main(string[] args)
    {
        Console.WriteLine(Reverse("Test"));
        Console.WriteLine(Reverse("Fun"));
        Console.WriteLine(Reverse("Airport"));
        Console.WriteLine(Reverse("Game"));
        Console.ReadKey();
    }
}
