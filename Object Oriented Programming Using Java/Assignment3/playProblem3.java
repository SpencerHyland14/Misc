import java.util.Scanner;

public class playProblem3{
	public static void main(String[] args) {
		//Scanner initialization
		Scanner sc = new Scanner(System.in);
		//Object declaration for the problem 3 class
		problem3 test = new problem3();
		//Initializes the board
		test.initializeBoard();
		//Prints the empty board
		test.printBoard();
		//Lets the players take turns until someone wins or the board becomes full
		while((test.checkWin()==false) || (test.isFull())) {
			System.out.println("Please enter the coordinates of your move eg.(1,2)");
			String input = sc.nextLine();    // get the entire line after the prompt 
			String[] numbers = input.split(","); // split by spaces
			int m = Integer.parseInt(numbers[0]);
			int n = Integer.parseInt(numbers[1]);
			test.playerMove(m, n);
			test.printBoard();
			if(test.checkWin()) {
				test.whoWon();
				break;
			}
			if(test.isFull() && !(test.checkWin())) {
				System.out.println("The board is full its a scratch");
				break;
			}
			
		}
		
		sc.close();
	}
}