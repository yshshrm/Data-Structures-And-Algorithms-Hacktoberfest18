namespace Solution
{
    public static class Program
    {
        public static double basicOp(char operation, double value1, double value2)
        {
            double result = 0;

            switch (operation)
            {
                case ('+'):
                    result = value1 + value2;
                    break;
                case ('-'):
                    result = value1 - value2;
                    break;
                case ('*'):
                    result = value1 * value2;
                    break;
                case ('/'):
                    result = value1 / value2;
                    break;
            }
            // end of switch
            return result;
        }
    }
}