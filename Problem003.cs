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
