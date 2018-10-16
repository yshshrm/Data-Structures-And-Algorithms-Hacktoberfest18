package com.java.trials;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;




public class FlamesMagic {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.println("Crazy!! Lets do a small trick and find relation between two persons...");
		System.out.println("================**CAUTION** Its Just for FUN!!=================");
		System.out.println("Please enter two names:\n");
		char[] c1,c2;
		/*String s1,s2;
		s1=scan.next();
		s2=scan.next();
		c1=new char[s1.length()];
		c2=new char[s2.length()];
		c1=s1.toLowerCase().toCharArray();
		c2=s2.toLowerCase().toCharArray();*/
		c1=(scan.next()).toLowerCase().toCharArray();
		c2=(scan.next()).toLowerCase().toCharArray();
		scan.close();
		ArrayList<Character> container = new ArrayList<Character>();
		for(int i=0;i<c1.length;i++)
			container.add(c1[i]);
		for(int i=0;i<c2.length;i++)
		{
			if(container.contains(c2[i]))
				container.remove(container.indexOf(c2[i]));
			else
				container.add(c2[i]);
		}
		ArrayList<Character> flames = new ArrayList<Character>();
		flames.add('F');
		flames.add('L');
		flames.add('A');
		flames.add('M');
		flames.add('E');
		flames.add('S');
		int base = container.size(),counter=0;
		if(base==0)
		{
			System.out.println("You both are perfect match!!!");
			return;
		}
		Iterator<Character> it=flames.iterator();
		for(int i=1;flames.size()!=0;i++)
		{
			if(counter==5 || !it.hasNext())
			{
				it=flames.iterator();
				if(counter==5){
				char res=it.next();
				if(res=='F')
				System.out.println("Hey!!! You are FRIENDS");
				if(res=='L')
					System.out.println("Areyyy!!! You are LOVERS");
				if(res=='A')
					System.out.println("Oyee!!! He/She needs your ATTENTION");
				if(res=='M')
					System.out.println("Hey..congo!!! You are going to get MARRIED :)");
				if(res=='E')
					System.out.println("Uffo!!! You are ENEMIES :(");
				if(res=='S')
					System.out.println("Hey!!! You are SISTERS");
				break;}
			}
			it.next();
			if(i==base)
			{
				it.remove();
				i=0;
				counter++;
			}
			
		}
	}

}
