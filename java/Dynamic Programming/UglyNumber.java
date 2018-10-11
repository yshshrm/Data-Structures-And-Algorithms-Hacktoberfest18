import java.util.Scanner;

public class UglyNumber {
    public static int helper_ugly(int n){
        int[] ugly=new int[n+1];
        ugly[0]=1;
        int i2=0,i3=0,i5=0;
        int next_multiple_2=2;
        int next_multiple_3=3;
        int next_multiple_5=5;
        int next_num=1;
        for(int i=1;i<n;i++)
        {
            next_num=Math.min(next_multiple_2,Math.min(next_multiple_3,next_multiple_5));
            ugly[i]=next_num;
            if(next_num==next_multiple_2)
            {
                i2++;
                next_multiple_2=ugly[i2]*2;
            }
            if(next_num==next_multiple_3)
            {
                i3++;
                next_multiple_3=ugly[i3]*3;
            }
            if(next_num==next_multiple_5)
            {
                i5++;
                next_multiple_5=ugly[i5]*5;
            }
        }

        return next_num;
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(helper_ugly(n));

            }
}
