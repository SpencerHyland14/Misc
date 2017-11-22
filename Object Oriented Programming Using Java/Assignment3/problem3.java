public class problem3{
	private char board[][];
	private char currentPlayerMark;
	
	//Initializes the player board by calling the initialize function
	//Also initializes varialbes
	public problem3(){
		board = new char[3][3];
		currentPlayerMark = 'x';
		initializeBoard();
	}
	
	//Initializes the 3x3 array with blank spaces
	public void initializeBoard() {
		for(int i=0; i<3; i++) {
			for (int j=0; j<3; j++)
				board[i][j] = ' ';
		}
	}
	
	//Prints the board position by position separated by the '|'
	public void printBoard() {
		for (int i = 0; i<3; i++) {
			System.out.print("| ");
			for(int j = 0; j<3; j++) {
				System.out.print(board[i][j]+ " | ");
			}
			System.out.println();
			System.out.println("------------");
		}
	}
	
	//Player move function checks to see if the position they are moving to is available 
	//and also calls the mark board function and marks the board with the corresponding mark
	public void playerMove(int m, int n){
		if (availablility(m, n) == true)
			markBoard(m,n);
		else 
			System.out.println("Position already used try again please");
	}
	
	//Checks the availability of a position by making sure that there is a blank space
	//at the position entered by the user
	public boolean availablility(int m, int n) {
		if(board[m][n] == ' ')
			return true;
		else
			return false;
	}
	
	//Marks the board at the position entered by the user, than changes the value
	//of the currentPlayerMark variable
	public void markBoard(int m, int n) {
		if (currentPlayerMark == 'x') {
			board[m][n] = 'o';
			currentPlayerMark = 'o';
		}
		else {
			board[m][n] = 'x';
			currentPlayerMark = 'x';
		}
	}
	
	//Checks all the possible win combinations to see if there is a win 
	public boolean checkWin() {
		if((board[0][0]==board[1][1]) && (board[1][1]==board[2][2])) {
			if((board[0][0] != ' ') || (board[1][1]!= ' ') || (board[2][2] != ' '))
				return true;
		}
		else if((board[0][2]==board[1][1]) && (board[1][1]==board[2][0])) {
			if((board[0][2] != ' ') || (board[1][1]!= ' ') || (board[2][0] != ' '))
				return true;
		}
		for(int i = 0; i<3; i++) {
			if((board[i][0]==board[i][1]) && (board[i][1]==board[i][2])) {
				if((board[i][0] != ' ') || (board[i][1]!= ' ') || (board[i][2] != ' ')) {
					return true;
				}
			}
			else if((board[0][i]==board[1][i]) && (board[1][i]==board[2][i]))
				if((board[0][i] != ' ') || (board[1][i]!= ' ') || (board[2][i] != ' ')) {
					return true;
				}
		}
		return false;
	}
	
	//Prints which player won dependent on which mark was last placed
	public void whoWon() {
		if (currentPlayerMark == 'o') {
			System.out.println("Player 1 won!");
		}
		else 
			System.out.println("Player 2 won!");
	}
	
	//Checks the board for blank spaces, if there is none
	//and no player has won than the game is a scratch
	public boolean isFull() {
		for(int i = 0; i<3; i++) {
			for(int j = 0; j<3; j++) {
				if (board[i][j] == ' ')
					return false;
			}
		}
		return true;
	}
}