import java.math.BigInteger;
import java.util.ArrayList;


public class Prob20 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BigInteger number = BigInteger.ONE;
		for (int i = 2; i <= 100; i++)
			number = number.multiply(BigInteger.valueOf(i));
		
		System.out.println(number);
		// separate number into array of ints 
		BigInteger n = BigInteger.TEN;	
		// array to hold digits
		ArrayList<BigInteger> digits = new ArrayList<BigInteger>();
		// take mod 10 
		// add it to the array then subtract it from number 
		// then divide number by 10
		for (int i = 0; i < 200; i++){
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
