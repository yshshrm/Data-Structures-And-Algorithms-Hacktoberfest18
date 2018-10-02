import java.io.File;
import java.util.Formatter;
import java.util.Scanner;
class Five{
public static void main(String [] args){
String []a=new String[50];
Scanner w=new Scanner(System.in);
int i=0,c=0,l,h;
String b; 
System.out.println("enter no of stop words");//input to take no of stop words 
h=w.nextInt();

String [] d=new String[h];
System.out.println("enter "+h+" stop characters");
for(l=0;l<h;l++){
	// read the stop words from the user
	d[l]=w.next();
	}
	
try{
	File f=new File("test.txt");
	Scanner s=new Scanner(f);
	while(s.hasNext()){
		// reading the file and storing words in array
		a[i]=s.next();
		c=c+1;
		i=i+1;
		}
	for(i=0;i<c;i++){
			b=a[i];
		for(l=0;l<h;l++){
			if(b.equals(d[l])){
			/* strings can not be directly checked whether they are equal or not by'==' sign so use "string1.equals(string2)" 					returns true if the two strings are equal*/
				a[i]=" ";
			continue;
			}
	}
	
	}
	s.close();
}catch(Exception e){
	System.out.println("error");
	}
	for(i=0;i<c;i++){
	// printing the modified text
			System.out.print(a[i]);
			System.out.print(" ");
	}
}
}
