/*
 Spencer Hyland
 104449507
 03-60-212
 Assignment 2
 Problem 2
 */
public class microwave{
	private int time;
	private boolean pLevel;
	
	public microwave() {
		this.time = 0;
		this.pLevel = false;
	}
	
	public void switchLevel() {
		this.pLevel = !this.pLevel;
	}
	
	public void timer() {
		this.time += 30;
	}
	
	public void resetTime() {
		this.time = 0;
	}
	
	public void start() {
		System.out.println("Cooking for "+this.time+" seconds at level "+(this.pLevel?2:1));
	}
}
