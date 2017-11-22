public class PrimeGenerator
{
	private int current;
	public PrimeGenerator()
	{
		current = 2;
	}
	/**
 	Calculates the next prime number.
 	@return the next prime number
 	*/
	public void nextPrime(int limit)
	{
		for (int i = current; i<=limit; i++) {
			if(isPrime(i)==true) {
				System.out.println(i);
			}
		}
		
	}
	public static boolean isPrime(int n) {
		boolean prime = true;
	    for (int i = 2; i < n; i++) {
	        if (n % i == 0) {
	            prime = false;
	            break;
	        }
	    }
	    if (prime) {
	    		return true;
	    }
	    else 
	    		return false;
	}
}