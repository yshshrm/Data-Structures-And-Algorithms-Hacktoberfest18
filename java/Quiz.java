import java.util.Scanner;
import java.util.*;
class Quizques
{
String question;
String answer;
public Quizques(String question,String answer)
{
	this.question=question;
	this.answer=answer;
}
}
class Quiz
{
public static void main(String args[])
{
	int count=0;
System.out.println("------------Welcome To The Java Quiz------------");
Quizques q1= new Quizques("What is correct syntax for main method of a java class?\nA - public static int main(String[] args)\nB - public int main(String[] args)\nC - public static void main(String[] args)\nD - None of the above.","c");
Quizques q2= new Quizques("Can we have two public classes in one java file?\nA - True\nB - False","b");
Quizques q3= new Quizques("What is the default value of float variable?\nA - 0.0d\nB - 0.0f\nC - 0\nD - not defined","b");
Quizques q4= new Quizques("Which of the following is false about String?\nA - String is immutable.\nB - String can be created using new operator.\nC - String is a primary data type.\nD - None of the above.","c");
Quizques q5= new Quizques("What is an immutable object?\nA - An immutable object can be changed once it is created.\nB - An immutable object can't be changed once it is created.\nC - An immutable object is an instance of an abstract class.\nD - None of the above.","b");
Quizques q6= new Quizques("Composition represents\nA - HAS-A relationship.\nB - IS-A relationship.","a");
Quizques q7= new Quizques("Dynamic binding uses which information for binding?\nA - type.\nB - object.\nC - Both of the above.\nD - None of the above.","b");
Quizques q8= new Quizques("What invokes a thread's run() method?\nA - JVM invokes the thread's run() method when the thread is initially executed.\nB - Main application running the thread.\nC - start() method of the thread class.\nD - None of the above.","a");
Quizques q9= new Quizques("Can constructor be inherited?\nA - True.\nB - False.","b");
Quizques q10= new Quizques("which operator is considered to be with highest precedence?\nA - () , []\nB - =\nC - ?:\nD - %","a");
Quizques q10= new Quizques("Which method is called when an object is destroyed by the Garbage collector?\nA - destruct(). \nB - finalize(). \nC - destroy(). \nD - None of the above.","b");

List<Quizques> list = new ArrayList<Quizques>();
Scanner scan=new Scanner(System.in);
Random rand =new Random();

list.add(q1);
list.add(q2);
list.add(q3);
list.add(q4);
list.add(q5);
list.add(q6);
list.add(q7);
list.add(q8);
list.add(q9);
list.add(q10);
int a=list.size();
for(int i=0;i<a;i++)
{
	int randomIndex= rand.nextInt(list.size());
	Quizques randomElement= list.get(randomIndex);
	System.out.println(randomElement.question);
	
	String ans;
	ans=scan.next();
	if(ans.equals(randomElement.answer))
		count++;
	else
		continue;
	
	list.remove(randomIndex);
}
System.out.println("Score: "+count);
}
}
