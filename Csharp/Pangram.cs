using System;
using System.Linq;

namespace Pangram {
	class Program {
		static bool IsPangram(string sentence) {
			char[] arr = sentence.ToCharArray();
			char[] letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

			foreach (char letter in letters) {
				char lower = char.ToLower(letter);
				char upper = char.ToUpper(letter);
				if (!(arr.Contains(upper) || arr.Contains(lower))) {
					return false;
				}
			}
			return true;
		}

		static void Main() {
			string str1 = "The quick brown fox jumps over the lazy dog.";
			string str2 = "The quick brown fox jumped over the lazy dog.";
			Console.WriteLine(IsPangram(str1)? "It is a pangram." : "It's not a pangram!");
			Console.WriteLine(IsPangram(str2)? "It is a pangram." : "It's not a pangram!");

		}
	}
}