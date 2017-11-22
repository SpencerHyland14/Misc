/*
 Spencer Hyland
 104449507
 03-60-212
 Assignment 2
 Problem 3 tester
 */
public class problem3
{
   public static void main(String[] args)
   {
      //Creates an objective of the class "BankAccount
      BankAccount harrysChecking = new BankAccount();
      //Loop to generate deposits
      for(int i = 0; i<12; i++) {
    	      harrysChecking.deposit(20);
      }
      
      //Loop to generate withdraws 
      for(int i = 0; i<7; i++) {
    	      harrysChecking.withdraw(5);
      }
      //Method to deduct the monthly charge
      harrysChecking.deductMonthlyCharge();
      System.out.println(harrysChecking.getBalance());
      System.out.println("Expected: 179.0");   
   }
}