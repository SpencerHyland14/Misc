import java.util.Scanner;

public class problem4{
	public static void main(String[] args) {
		//Scanner declaration
		Scanner sc = new Scanner(System.in);
		//Bounds declaration and initialization via recieveBounds function
		int bounds = 0; 
		bounds =receiveBounds(bounds, sc);
		//Terrain map declaration and initialization via the populate function
		int[][] terrainMap = new int[bounds][bounds];
		terrainMap = populate(terrainMap, bounds, sc);
		//Function calls
		printTerrain(terrainMap, bounds);
		lowestPoint(terrainMap, bounds);
		highestPoint(terrainMap, bounds);
		checkFlood(terrainMap, bounds, sc);
		//Scanner close
		sc.close();
	}
	//Function to receive the bounds for the map
	private static int receiveBounds(int bounds, Scanner sc) {
		System.out.println("Please enter the size of your array");
		bounds = sc.nextInt();
		return bounds;
	}
	//Function to populate the array via user input for their map
	private static int[][] populate(int[][] terrainMap,int bounds, Scanner sc) {
		for(int i = 0; i < bounds; i++) {
			for(int j = 0; j < bounds; j++) {
				System.out.print("Please enter the height of the terrain at position ("+i+", "+j+") ");
				terrainMap[i][j] = sc.nextInt();
			}
		}
		return terrainMap;
	}
	//Function to print the terrain map heights
	private static void printTerrain(int[][] terrainMap, int bounds) {
		for(int i = 0; i < bounds; i++) {
			for(int j = 0; j < bounds; j++) {
				System.out.print(terrainMap[i][j] + " ");
			}
		System.out.println();
		}
	}
	//Function to find the lowest point in the map
	private static void lowestPoint(int [][]terrainMap, int bounds){
		int lowest = terrainMap[0][0];
		for(int i=0; i<bounds; i++) {
			for(int j=0; j<bounds; j++) {
				if(terrainMap[i][j] < lowest) {
					lowest = terrainMap[i][j];
				}
			}
		}
		System.out.println("The lowest point in the Terrain Map is "+lowest);
	}
	//Function to find the highest point in the map
	private static void highestPoint(int [][]terrainMap, int bounds){
		int highest = terrainMap[0][0];
		for(int i=0; i<bounds; i++) {
			for(int j=0; j<bounds; j++) {
				if(terrainMap[i][j] > highest) {
					highest = terrainMap[i][j];
				}
			}
		}
		System.out.println("The highest point in the Terrain Map is "+highest);
	}
	/*Function to take the water level via user input and run through the height map
	then finds which locations will flood and populates the flood map with the
	flood symbol('*') or the safe symbol('-') then prints the symbol*/
	private static void checkFlood(int [][] terrainMap, int bounds, Scanner sc) {
		char [][] floodMap = new char[bounds][bounds];
		System.out.println("Please enter the height of the water level");
		int level = sc.nextInt();
		for(int i=0; i<bounds; i++) {
			for(int j=0; j<bounds; j++) {
				if(terrainMap[i][j] > level)
					floodMap[i][j] = '-'; 
				else
					floodMap[i][j] = '*';
				System.out.print(floodMap[i][j]+" ");
			}
			System.out.println();
		}
	}
}