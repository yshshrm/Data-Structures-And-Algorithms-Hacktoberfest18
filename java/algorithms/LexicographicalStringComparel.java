/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package String;

import java.util.Scanner;

/**
 *
 * @author SYSTEM
 */
public class LexicographicalStringComparel {
   
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        System.out.println(A.length() + B.length());
        int x = A.compareTo(B);
        System.out.println(A.compareTo(B)>0 ? "Yes" : "No"); 
        String z,y;
        z=A.substring(0,1).toUpperCase();
        y=B.substring(0,1).toUpperCase();
        System.out.println(z + A.substring(1) + " " + y + B.substring(1));
        
    }
}
    

