/*
* Copyright 2013 Ben Cordero
*
* This file is part of my ProjectEuler implementations.
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
