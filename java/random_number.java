package GitHub.contributions;

import java.util.Random;
import java.util.Scanner;

public class RandomNumber {

    public static void main(String[] args) {

        System.out.println("Random Number Generator");
        System.out.println("Please enter the maximum: ");
        Scanner scan = new Scanner(System.in);
        int max = scan.nextInt();
        System.out.println("Please enter the minimum: ");
        int min = scan.nextInt();
        Random rand = new Random();
        int randomInt = rand.nextInt(max)+ min;
        System.out.println("Random number: " + randomInt);

    }
}
