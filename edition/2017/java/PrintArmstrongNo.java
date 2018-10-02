import java.util.Scanner;

public class ArmstrongNo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter Two Numbers");
		int a = scn.nextInt();
		int b = scn.nextInt();
		
		while (a<=b)
		{

			int n = a;
			int c = 0;
			while (n!=0)
			{
				int rem = n % 10;
				c = c + (rem*rem*rem);
				n /= 10;
			}
			if (c == a)
			{
				System.out.print(c + " ");
			}
			a++;
		}
	}

}
