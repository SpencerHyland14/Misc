/*
 Spencer Hyland
 104449507
 03-60-212
 Assignment 2
 Problem 2 tester
 */
public class problem2{
	public static void main(String[] args) {
		//Creates an object of the class "microwave"
		microwave test = new microwave();
		//Method calls
		test.timer();
		test.switchLevel();
		test.start();
		System.out.println("Expected: Cooking for 30 seconds at level 2");
		test.resetTime();
		System.out.println("The output after being reset is: ");
		test.start();
		System.out.println("Expected: Cooking for 0 seconds at level 2");
	}
}
