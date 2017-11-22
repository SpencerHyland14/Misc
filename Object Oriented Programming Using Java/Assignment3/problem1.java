

/*
 Spencer Hyland
 104449507
 Java Programming
 Assignment 3
 Problem 1
 */

import java.util.Scanner;

public class problem1{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Please enter your card number(16 digits)");
		String cardNo = sc.nextLine();
		cardNo = cardNo.replaceAll("\\s+", "");
		System.out.println(cardNo);
		p1validator test = new p1validator();
		test.validate(cardNo);
		sc.close();
		
	}	
	
}