
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first
 * ten terms would be:
 * 
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 * 
 * Let us list the factors of the first seven triangle numbers:
 * 
 * 1: 1 3: 1,3 6: 1,2,3,6 10: 1,2,5,10 15: 1,3,5,15 21: 1,3,7,21 28:
 * 1,2,4,7,14,28
 * 
 * We can see that 28 is the first triangle number to have over five divisors.
 * 
 * What is the value of the first triangle number to have over five hundred
 * divisors?
 * 
 * @link <a href="http://en.wikipedia.org/wiki/Divisor_function">Divisor Function</a>
 * @link <a
 *       href="http://projecteuler.net/index.php?section=problems&id=12">Problem
 *       12</a>
 * @author Cesar Arevalo
 */
public class Problem012 {

	/**
	 * This method returns the primes in the first {@code n} numbers.
	 * 
	 * <p/>
	 * 
	 * Please look at {@link Problem010_SieveOfErastothenes} on how to generate
	 * prime numbers.
	 * 
	 * @param n
	 * @return
	 */
	public static Integer[] getFirstPrimeNumbers(Integer n) {
		int limit = n;
		long squareOfLimit = Double.valueOf(Math.sqrt(limit)).longValue();
		int numberInIteration = 0;
		long squareOfi = 0;

		int[] numbers = new int[limit];

		// 1. Consider a contiguous list of numbers from two to some maximum.
		for (int i = 2; i <= n; i++) {
			numbers[i - 2] = i;
		}

		// 2. Strike off all multiples of 2 greater than 2 from the list.
		int numberToStrikeOff = 0;
		int index2 = 0;

		for (int i = 1; i < squareOfLimit; i++) {
			numberToStrikeOff = i + 1;
			squareOfi = i * i;

			index2 = i;
			while (index2 < numbers.length) {
				numberInIteration = numbers[index2];
				if (numberInIteration < squareOfi) {
				}
				else if (numberInIteration % numberToStrikeOff == 0) {
					numbers[index2] = 0;
				}
				index2++;
			}
		}

		List<Integer> returnValues = new ArrayList<Integer>();
		for (int i=0; i < n; i++) {
			if (numbers[i] > 0) {
				returnValues.add(numbers[i]);
			}
		}

		return returnValues.toArray(new Integer[returnValues.size()]);
	}

	public static void main(String[] args) {
		Date startDate = new Date();
		System.out.println("startDate: " + startDate.getTime());

		// Get the some prime factors
		int limitOfPrimeFactors = 100;
		Integer[] primeFactors = getFirstPrimeNumbers(limitOfPrimeFactors);
		System.out.println("primeFators: ");
		for (int i = 0; i < primeFactors.length; i++) {
			System.out.print(primeFactors[i] + ", ");
		}
		System.out.println();

		int triangleNumber = 1;

		// the number of divisors of n
		int functionOfTau = 1;

		for (int indexForFindingTriangleNumber = 1; functionOfTau < 500; indexForFindingTriangleNumber++) {
			triangleNumber = (indexForFindingTriangleNumber * (indexForFindingTriangleNumber + 1)) / 2;
			System.out.println("triangleNumber = " + triangleNumber);

			// find r
			int r = 0;
			int indexForFindingR = 0;
			int limitInLoop = triangleNumber / 2;
			//System.out.println("limitInLoop = " + limitInLoop);

			List<Integer> primeFactorsOfN = new ArrayList<Integer>();
			
			boolean foundR = false;
			while (!foundR) {
				if (triangleNumber % primeFactors[indexForFindingR] == 0) {
					primeFactorsOfN.add(primeFactors[indexForFindingR]);
					r++;
				}
				indexForFindingR++;
				if (indexForFindingR > limitInLoop || indexForFindingR >= primeFactors.length) {
					foundR = true;
				}
			}

			System.out.println("r = " + r);

			System.out.println("primeFactorsOfN = " + primeFactorsOfN);

			// determine the maximum powers of n
			Map<Integer, Integer> maximumPowersOfP = new HashMap<Integer, Integer>();
			boolean maximumPowerFound = false;
			for (Integer primeFactorOfN : primeFactorsOfN) {
				maximumPowerFound = false;

				int i = 0;
				while (!maximumPowerFound) {
					if (triangleNumber % Math.pow(primeFactorOfN, i) == 0) {
						maximumPowersOfP.put(primeFactorOfN, i);
					}
					else {
						maximumPowerFound = true;
					}
					i++;
				}
			}

			System.out.println("maximumPowersOfP: " + maximumPowersOfP);
			
			// find the Tau function of triangleNumber
			functionOfTau = 1;
			for (Integer maximumPowerOfP : maximumPowersOfP.values()) {
				functionOfTau *= (maximumPowerOfP + 1);
			}

			System.out.println("functionOfTau = " + functionOfTau);
		}

		Date endDate = new Date();
		System.out.println("endDate: " + endDate.getTime());
	}
}
