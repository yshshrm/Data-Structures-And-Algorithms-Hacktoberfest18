/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package String;
import java.lang.*;
import java.util.*;
/**
 *
 * @author sohai
 */
public class StringCountBetween {
    
    static void count(String s)
    {
        char a[] = s.toCharArray();
        char start = a[0];
        char end = a[a.length-1];
        int sum=0;
        for(int i= 1; i< a.length - 1 ; i++)
        {
            sum=sum+1;
        }
        String sb = Character.toString(start) + String.valueOf(sum) + Character.toString(end);
        System.out.println(sb);
    }
    
    static boolean checkPrime(int n)
    {
        if(n<=1)
            return false;
        else if(n==2)
            return true;
        else{
            for(int i=2 ; i < n ; i++)
                if(n%i==0)
                    return false;
            }
        return true;
    }
    
    
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(checkPrime(n));
        
//        String [] name = new String[n+1];
//        
//        for(int i = 0; i < n+1 ; i++)
//        {
//        name[i] = sc.nextLine();
//         if(name[i].length()>10)
//            count(name[i]);
//        else
//            System.out.println(name[i]);
//        }
//        
    }
}