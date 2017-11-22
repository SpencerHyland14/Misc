/*
Spencer Hyland
03-60-212
Assignment 1
Question 3
*/

public class q3 {
	public static void main(String argv[]) {
		//Variable declaration and initialization
		int sum=0;
		int product=1;
		
		//Print statement 
		System.out.println("The sum and product of the integers (-1 to -5) is:");
		
		//For loop for running through numbers -1 to -5
		//calculating the sum and product of the integers
		for (int counter=-1; counter >= -5; counter--){
			sum += counter;
			product *= counter;
		}
		
		//Prints the final sum of the integers and the final product of the integers
		System.out.println("Sum: "+sum);
		System.out.println("Product: "+product);
	}
	
}