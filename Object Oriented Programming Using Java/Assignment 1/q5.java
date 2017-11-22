/*
Spencer Hyland
03-60-212
Assignment 1
Question 5
*/

public class q5{
	public static void main(String argv[]) {
		//Variable declaration and initialization
		int s = 5;
		int v = 7;
		int g = 3;
		int t = 2;
		double outcomeS=0;
		double outcomeG=0;
		
		//First function that is asked to calculate
		outcomeS = s + v + 0.5*(g*(Math.pow(t, 2)));
		//Print statement for the outcome
		System.out.println("s = "+outcomeS); 
		
		//Variable declaration and initialization 
		int a=6;
		int p=2;
		//Second function that is asked to calculate
		//Used Math.PI function to get the exact value of Pi instead of estimating
		outcomeG = 4 * Math.pow(Math.PI, 2) * Math.pow(a, 3)/(Math.pow(p, 2) * (g + t));
		//Print statement for the second outcome
		System.out.println("G = "+outcomeG);
	}
	
			
			
}