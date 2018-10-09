

import java.util.*;

public class CountCircleWide{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        
        double phi = 3.14;
        double r, wide,circum;
        
        System.out.println("Program Luas Lingkaran\n");
        System.out.print("Masukkan Panjang Jari-jari : ");
        r = s.nextDouble();

        wide = 0.5 * phi * r * r;
        circum = 2 * phi * r;

        System.out.print("Luas Lingkaran = " + (int)wide + " \nKeliling lingkaran = "+ (int)circum);
    }
}
