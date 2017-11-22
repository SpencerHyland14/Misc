/*
 Spencer Hyland
 104449507
 03-60-212
 Assignment 2
 Problem 3
 */
public class BankAccount
{  
   private double balance;
   private int tAmount;
   private double deduction;

   /**
      Constructs a bank account with a zero balance.
   */
   public BankAccount()
   {   
      balance = 0;
      this.tAmount = 0;
      this.deduction = 0;
   }

   /**
      Constructs a bank account with a given balance.
      @param initialBalance the initial balance
   */
   public BankAccount(double initialBalance){   
      balance = initialBalance;
   }

   /**
      Deposits money into the bank account.
      @param amount the amount to deposit
   */
   public void deposit(double amount){  
      balance = balance + amount;
      if(this.tAmount > 5) {
    	       this.deduction += 2;
      }
      this.tAmount += 1;
   }

   /**
      Withdraws money from the bank account.
      @param amount the amount to withdraw
   */
   public void withdraw(double amount)
   {   
      balance = balance - amount;
      if(this.tAmount > 5) {
    	       this.deduction += 2;
      }
      this.tAmount += 1;
   }
   /**
      Gets the current balance of the bank account.
      @return the current balance
   */
   public double getBalance()
   {   
      return balance;
   }
   //Deducts the monthly charge after the alotted amount of transactions
   //have been tallied and added to the deduction amount
   public void deductMonthlyCharge(){
	   balance-= this.deduction;
   }
}