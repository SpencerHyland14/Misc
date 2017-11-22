/*
 Spencer Hyland
 104449507
 03-60-212
 Assignment 2
 Problem 4
 */
import java.util.Scanner;

public class problem4{
	public static void main(String[] args) {
		//Scanner declaration
		Scanner sc = new Scanner(System.in);
		//Variable declaration and initialization
		int dollars= 0, quarters = 0, dimes = 0, nickels = 0, pennies =0;
		int change;
		
		//Prompt for user to enter the amount due
		System.out.println("Enter the Amount due");
		int aDue=sc.nextInt();
		
		//Prompt for user to enter the amount payed
		System.out.println("Enter the Amount payed");
		int aPayed = sc.nextInt();
		
		//Calculates the change due
		change = aPayed - aDue;
		
		//Calculates the change due by the coin due
		dollars = change/100;
		change %= 100;
		
		quarters = change/25;
		change %=  25;
		
		dimes = change/10;
		change %= 10;
		
		nickels = change/5;
		change %= 5;
		
		pennies = change/1;
		change %= 1;
		
		//Prints each coins ammount
		System.out.println("Dollars: "+dollars);
		System.out.println("Quarters: "+quarters);
		System.out.println("Dimes: "+dimes);
		System.out.println("Nickels: "+nickels);
		System.out.println("Pennies: "+pennies);
		
		sc.close();
	}
}