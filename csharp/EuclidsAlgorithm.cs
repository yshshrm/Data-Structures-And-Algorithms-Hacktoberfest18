using System;

namespace Euclid {
	class Program {
		static int EuclidsAlgorithm(int a, int b) {
			while (b != 0) {
				if (a > b) {
					a -= b;
				} else {
					b -= a;
				}
			}
			return a;
		}

		static void Main() {
			Console.WriteLine(EuclidsAlgorithm(4, 22));
		}
	}
}