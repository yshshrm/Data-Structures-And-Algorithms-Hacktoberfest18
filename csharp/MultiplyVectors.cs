namespace MultiplyVectors
{
    /* a simple program for multiplying vectors if you know their coordinates and the value
     * of Cos(Vector1 /\ Vector2)
     * 
     * made by Miautawn
     */


    public class MyVector
    {
      public MyVector(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public int x;
        public int y;
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyVector first, second;
            int tempX, tempY;
            Double moduleN1, moduleN2, valueOfCosinus, result;

                Console.WriteLine("Please enter Vector.n1 X:");
                tempX = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Please enter Vector.n1 Y:");
                tempY = Convert.ToInt32(Console.ReadLine());
                first = new MyVector(tempX, tempY);

            Console.WriteLine("Please enter Vector.n1 X:");
            tempX = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Please enter Vector.n1 Y:");
            tempY = Convert.ToInt32(Console.ReadLine());
            second = new MyVector(tempX, tempY);


            moduleN1 = Math.Sqrt(Math.Pow(first.x, 2) + Math.Pow(first.y, 2));
            moduleN2 = Math.Sqrt(Math.Pow(second.x, 2) + Math.Pow(second.y, 2));
            Console.WriteLine("Please enter the value of the cosinus that is between your vectors: ");
            valueOfCosinus = Convert.ToDouble(Console.ReadLine());

            result = moduleN1 * moduleN2 * valueOfCosinus;
            Console.WriteLine("result is: " + result);
 
        }
    }
}