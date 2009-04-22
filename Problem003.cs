/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

using System;
using System.Numeric;	// Pretend BigInteger is a new primative.

class Euler3{
		
	public static void Main()	{
		
		BigInteger a = 600851475143;
		BigInteger b = 1;
		
		while (b!=-1){
			a = a/b;
			b = BigFactor(a); 
		}
		
		Console.WriteLine("{0}",a);
	}
	
	static BigInteger BigFactor(BigInteger a){
		
	BigInteger i;
	for (i = 2;i<a;i++)
	{
		if ((a%i)==0)
		{
			return i;
		}
	}
	
	return -1;
	}
}