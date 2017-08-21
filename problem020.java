import java.math.BigInteger;

/* Since an implementation in C would have been at least 4 times as long
 * and time consuming (ie. implementing BigInteger in C is a handful), I
 * chose a simple Java solution. */

public class problem020 {
	
	public static void main(String[] args) {
		BigInteger value = BigInteger.valueOf(1);
		
		for (int i = 1; i < 101; i++) {
			value = value.multiply(BigInteger.valueOf(i));
		}
		
		String s = value.toString();
		int sum = 0;
		
		for (int i = 0; i < s.length(); i++) {
			int j = Integer.parseInt(s.substring(i, i+1));
			sum += j;
		}
		
		System.out.println(sum);
	}
}
