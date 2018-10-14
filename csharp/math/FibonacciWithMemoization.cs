 namespace solution {
 
 public static class FibonacciWithMemoization
    {
        public const int CACHE_SIZE = 100;
        private static int[] _cache;

        static FibonacciWithMemoization()
        {
            _cache = new int[CACHE_SIZE];
        }

        public static int NthFib(int n)
        {
            if (n <= 0)
                return 0;

            if (n == 1)
                return 1;

            if (n < CACHE_SIZE)
            {
                if (_cache[n] != 0)
                    return _cache[n];
                else
                    return _cache[n] = NthFib(n - 1) + NthFib(n - 2);
            }
            else
            {
                return NthFib(n - 1) + NthFib(n - 2);
            }
        }
	}
}