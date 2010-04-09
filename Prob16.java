import java.math.BigInteger;
import java.util.ArrayList;


public class Prob16 {

	public static void main(String[] args){
		BigInteger number = BigInteger.valueOf(2);
		number = number.pow(1000);
		System.out.println("2 ^ 1000 = "+ number+"\n");
		// separate number into array of ints 
		BigInteger n = BigInteger.TEN;	
		// array to hold digits
		ArrayList<BigInteger> digits = new ArrayList<BigInteger>();
		// take mod 10 
		// add it to the array then subtract it from number 
		// then divide number by 10
		for (int i = 0; i < 400; i++){
			BigInteger temp = number.mod(BigInteger.TEN);
			digits.add(temp);
			number = number.subtract(temp);
			number = number.divide(BigInteger.TEN);
		//	System.out.println(number);
		}
		System.out.println();
		BigInteger ans = BigInteger.ZERO;

		System.out.println();
		for (BigInteger num: digits){
			System.out.print(num+":");
			 ans = ans.add(num);
		}
		System.out.println("\nSum of digits is "+ans);
		
	}
}
