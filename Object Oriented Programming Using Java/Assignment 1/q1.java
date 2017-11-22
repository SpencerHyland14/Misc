/*
Spencer Hyland
03-60-212
Assignment 1
Question 1
*/

public class q1{
	public static void main(String argv[]) {
		//Variable declaration and initialization
		double balance=1000; 
		double rate = 0.05;
		double yearly=0; 
		
		//For loop to run through three years of having a bank account
		//And calculates the new balance after each year
		 for (int year=1; year<=3; year++) {
			 yearly = balance * rate; 
			 balance += yearly;
			 System.out.println("The balance after year "+year+" is: "+ balance);
		 }
		 //Prints the final balance after 3 years of having the account with 5% interest
		System.out.println("The final account balance after 3 years with an interest rate of 5% is: "+balance);
	}
}