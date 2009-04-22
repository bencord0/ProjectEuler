#include <stdio.h>
#include <stdbool.h>
 
#define IsEven(n) (n % 2) ? false : true
#define IsOdd(n) (n % 2) ? true : false
 
int main(void)
{
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long c;
    unsigned long m = 0;
 
 
    for(y = 999999; y > 0 ; y--)
    {
        x = y;
        c = 1;
 
        do
        {
            if(IsEven(x))
            {
                x /= 2;
            }
            else
            {
                x *= 3;
		x++;
            }
 
            c++;
 
            if(c > m)
            {
                m = c;
                z = y;
            }
        } while(x != 1);
	
    }
 
    printf("starting number = %lu, maximum chain = %lu\n", z, m);
 
    return 0;
}