using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;


public class FilterIntegers
{
    public static int[] FilterIntsFromString(string input)
    {
        List<int> integerList = new List<int>();
        var match = Regex.Match(input, @"\d+");
        while(match != null && !String.IsNullOrEmpty(match.Value))
        {
            int newInt = int.Parse(match.Value);
            if(match.Index > 0 && input[match.Index-1] == '-')
            {
                newInt *= -1;
            }
            integerList.Add(newInt);
            match = match.NextMatch();
        }
        return integerList.ToArray();
    }

    static void PrintIntArray(int[] array)
    {
        Console.WriteLine("Integer Array: ");
        for(int i = 0; i < array.Length; i++)
        {
            Console.Write(array[i]);
            if(i < array.Length-1)
            {
                Console.Write(", ");
            }
        }
        Console.WriteLine();
    }

    static void Main(string[] args)
    {
        PrintIntArray(FilterIntsFromString("-85HelloWorl65dTe5-6st"));
        PrintIntArray(FilterIntsFromString("-8Tea653218Test--5Piano000"));
        PrintIntArray(FilterIntsFromString("CakeNotTea"));
        PrintIntArray(FilterIntsFromString("Coffee9"));
        Console.ReadKey();
    }
}
