import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Prob18 {

	public ArrayList<String> readFile(Scanner s){
		ArrayList<String> lines = new ArrayList<String>();
		while(s.hasNextLine()){
			lines.add(s.nextLine());
		}
		return lines;
	}
	
	public ArrayList<Integer> readLine(String s){
		ArrayList<Integer> line = new ArrayList<Integer>();
		Scanner scan = new Scanner(s);
		while (scan.hasNextInt())
			line.add(scan.nextInt());
		return line;
	}
	
	public Triangle[] doLine(String s, Triangle[] pLine){
		Triangle[] triangles = new Triangle[pLine.length-1];
		
		return triangles;
	}
	
	public static void main(String args[]){
		Prob18 problem = new Prob18();
		ArrayList<String> text = new ArrayList<String>();
		try {
			Scanner hi = new Scanner(new File(args[0]));
			text = problem.readFile(hi);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(String s : text)
			System.out.println(s);
	}
}
