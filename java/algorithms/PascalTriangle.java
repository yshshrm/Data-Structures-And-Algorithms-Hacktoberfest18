package rekursif;
import java.util.Scanner;

public class PascalTriangle {
    public static int Pascal(int x, int y) {
        if(y == 0 || y == x) {
            return 1;
        }else {
            return Pascal(x-1, y-1) + Pascal(x-1, y);
        }
    }
    
    public static void main(String[] args) {
        Scanner scan =new Scanner(System.in);
        System.out.print("Input number of line : ");
        int row = scan.nextInt();
        int column = row;
        for(int i=0; i<=row; i++) {
            for (int j=0; j<=column; j++){
                System.out.print(" ");
            }
            for(int j=0; j<=i;j++) {
                System.out.print(Pascal(i, j) + " ");
            }
            System.out.println("");
            column--;
        }
    }
}