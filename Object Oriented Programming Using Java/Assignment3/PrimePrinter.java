import java.util.Scanner;
/**
This class prints prime numbers.
*/
	public class PrimePrinter{
		public static void main (String[] args){
			Scanner in = new Scanner(System.in);
			System.out.print("Enter upper limit: ");
			int limit = in.nextInt();
			PrimeGenerator test = new PrimeGenerator();
			test.nextPrime(limit);
			in.close();
		}
}