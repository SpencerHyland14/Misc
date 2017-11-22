public class p1validator{
	private int sum1;
	private int sum2;
	private int temp;
	private int oddNum;
	private int validCheck;

	public p1validator() {
		this.sum1 = 0; 
		this.sum2 = 0; 
		this.temp = 0;
		this.oddNum = 0;
		this.validCheck = 0;
	}
	
	public void validate(String cardNO){
		
		for (int i = 0; i < cardNO.length(); i++) {
			//Converts the ASCII to an int by subtracting the ASCII value
			this.temp = (cardNO.charAt(i) - '0');
			this.sum1 += this.temp;
		}
		
		this.temp = 0;
		
		for(int i = 0; i < cardNO.length(); i+=2) {
			this.temp = (cardNO.charAt(i) - '0');
			if(temp > 4){
				oddNum++;
			}
			this.sum2 += this.temp;
		}
		this.validCheck = this.sum1+this.sum2+this.oddNum;
		
		if((validCheck%10) == 0) {
			System.out.println("The credit card is valid");
		}
		else System.out.println("This credit card is invalid");
		
	}
	
}
