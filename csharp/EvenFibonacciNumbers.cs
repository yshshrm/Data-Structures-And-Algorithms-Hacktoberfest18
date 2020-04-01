namespace Fibonacci
{
    /// <summary>
    /// This class will return the sum of even fibonacci numbers.
    /// Credit to misterfoxy (https://github.com/misterfoxy) who's JavaScript
    /// version this is ported from (https://github.com/kvaluruk/Data-Structures-And-Algorithms-Hacktoberfest18/blob/master/javascript/Math/fibonacci.js)
    /// </summary>
    public class EvenFibonacciNumbers
    {
        private long _numberOne;
        private long _numberTwo;
        private long _numberThree;
        
        public EvenFibonacciNumbers()
        {
            _numberOne = 2;
            _numberTwo = 1;
            _numberThree = 0;
        }

        public long Sum(long maxNumber)
        {
            long total = 0;
            while (_numberOne < maxNumber)
            {
                if (_numberOne % 2 == 0)
                {
                    total += _numberOne;
                }

                _numberThree = _numberOne;
                _numberOne += _numberTwo;
                _numberTwo = _numberThree;
            }

            return total;
        }
    }
}
