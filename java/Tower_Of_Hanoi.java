import java.util.Scanner;

public class Tower_Of_Hanoi {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int nod = sc.nextInt();
		int count = towerOfHanoiSteps("Ring on 1", "Ring on 2", "Ring on 3", nod,0);
		 System.out.println("No. of Steps : " + count);
		sc.close();
	}

	private static int towerOfHanoiSteps(String p1, String p2, String p3, int no_of_discs,int count) {
		if (no_of_discs == 1) {
			System.out.println(p1 + " goes to " + p3);
			count++;
		} else {
			count = towerOfHanoiSteps(p1, p3, p2, no_of_discs - 1,count);
			System.out.println(p1 + " goes to " + p3);
			count++;
			count = towerOfHanoiSteps(p2, p1, p3, no_of_discs - 1,count);
		}
		return count;
	}
}
