/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

class Problem3	{
	public static void main(String[] args)	{		
		java.math.BigInteger a = new java.math.BigInteger("600851475143");
		java.math.BigInteger b = java.math.BigInteger.ONE;
		
		while ( !( b.equals(new java.math.BigInteger("-1") ) ) )	{ // b != -1
			a = a.divide(b);
			b = findFactor(a); 
		}
		
		System.out.println(a);
	}
	
	public static java.math.BigInteger findFactor(java.math.BigInteger a)	{
		java.math.BigInteger i;
		
		for (i = new java.math.BigInteger("2"); i.compareTo(a) == -1; i = i.add(java.math.BigInteger.ONE) )	{
			if ( ( a.remainder(i) ).equals(java.math.BigInteger.ZERO) )	{ // a%i == 0
				return i;
			}
		}
		
		return new java.math.BigInteger("-1");
	}
	
}