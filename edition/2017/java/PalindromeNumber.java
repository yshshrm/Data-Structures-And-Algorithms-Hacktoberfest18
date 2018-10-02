import java.io.*;
class Test{
	public void PalindromeNumber(int num){
		int n=0,digit,rev=0;
		n=num;
		do{
			digit=num%10;
			rev=(rev*10)+digit;
			num=num/10;
		}while(num!=0);

		System.out.println("The reverse number is : "+rev);
		if(rev==num)
			System.out.println("The number is Palindrome");
		else
			System.out.println("The number is Not Palindrome");
	}

	public static void public static void main(String[] args) {
		Test obj = new Test();
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int num;
		try{
			System.out.println("Enter a number : ");
			num=Integer.parseInt(br.readLine());
			obj.PalindromeNumber(num);
		}
		catch(Exception e){
			System.out.println(e);
		}

	}
}