/* ACHILLES NUMBERS */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COMPUTATIONS 10000000

int main()
{
	int numb,x,pow,div,f,gcd,max,min,temp,Sum,loop,y,z;
	f=0;
	Sum=0;
/*
	numb = testing number 
	y,z : numb = ((y mod 32768)+1) * ((z mod 32768)+1) + 1
	x = the number we process
	pow = the power of a prime number
	div = divider
	gcd = greatest common divisor
	Sum = number of ach. found
	loop = the number of loops done (defined by COMPUTATIONS)
	f = Guard number. If f=1 then numb<>achilles because we will find a power (pow) = 1

	*!IMPORTANT NOTE!* : GCD(A,B,C) = GCD(GCD(A,B),C)
	GCD is found via the Euclidean Algorithm
*/
	                                
		long now;
		now=time(NULL);																// now = current time
		srand((unsigned int)now);													// definition of rand()
	 	printf ("Current time is %ld\n\n",now);

	for (loop=1 ; loop<=COMPUTATIONS ; ++loop)
	{
		y = rand();
		z = rand();
		numb = 	(((y%32768)+1) * ((z%32768)+1)) + 1	;								// numb = "randomly" generated number by rand() function (defined by srand)
		x=numb;																		// we want numb intacted to check some conditions, so we creat a new variable that we will process																	
		pow=0;
		f=0;
		gcd=0;
		
		while (x%2==0)																// we divide as long as x mod 2 = 0
		{
			++pow;																	// pow = how many times 2 divides x
			x = x/2;																
		}
		
		if(pow==1)																	// if pow = 1 then the number is not powerful -> not achilles
		{
			continue;
		}
		else
		{
			gcd=pow;																// gcd = power of div if power<>1
			pow=0;																	// power = 0 so we can check the power of the next div
			while (x%3==0)
			{
				++pow;
				x = x/3;
			}
		}
		
		if(pow==1)
		{
			continue;
		}
		else if (gcd==0)															// if gcd=0 then we havent found a div. yet
		{
			gcd=pow;																
			pow=0;
		}
		else if (pow>1)																// in case gcd<>0 and c>1 then we have to find the new gcd
		{																			// check IMPORTANT NOTE in the comment section
			if (gcd>pow)
			{
				max=gcd;
				min=pow;
				while (min!=0)
				{
				temp=min;
				min=max%min;
				max=temp;
				}
				gcd=max;
			}
			else if (gcd<pow)
			{
				max=pow;
				min=gcd;
				while (min!=0)
				{
				temp=min;
				min=max%min;
				max=temp;
				}
				gcd=max;
			}
		}
		
		div=5;																		// suppose div = prime number -> in each loop we check div and (div+2) to see if they perfectly divide numb (x) (there is a "certain" sequence of primes)																
		while (div*div<=numb && div<=x) 											// We check till the root of the numb we process or till div.>x
		{
			pow=0;
			while (x%div==0)
			{
				++pow;
				x = x/div;
			}
			
			if(pow==1)
			{
				f=1;														
				break;
			}
			else if (gcd==0)
			{
				gcd=pow;															
				pow=0;
			}
			else if (pow>1)
			{
				if(gcd>pow)
				{
					max=gcd;
					min=pow;
					while(min!=0)
					{
						temp=min;
						min=max%min;
						max=temp;
					}
					gcd=max;														
				}
				else
				{
					max=pow;
					min=gcd;
					while(min!=0)
					{
						temp=min;
						min=max%min;
						max=temp;
					}
					gcd=max;
				}
			}

			pow=0;
			while (x%(div+2)==0)													
			{
				++pow;
				x = x/(div+2);
			}
			
			if (pow==1)
			{
				f=1;
				break;
			}
			else if (gcd==0)
			{
				gcd=pow;
				pow=0;
			}
			else if (pow>1)
			{
				if (gcd>pow)																		
				{
					max=gcd;
					min=pow;														
					while(min!=0)
					{
						temp=min;
						min=max%min;
						max=temp;
					}
					gcd=max;
				}
				else if (gcd<pow)
				{
					max=pow;
					min=gcd;
					while(min!=0)
					{
						temp=min;
						min=max%min;
						max=temp;
					}
					gcd=max;
				}
			}		
			div += 6;
		}
		
		if (f==0 && gcd==1 && div*div<numb)											//if this conditions if correct then numb = achilles										
		{
			++Sum;																	// sum = sum + 1 -> counter of achilles numbers 
    		printf ("%d is Achilles number\n",numb);                      
		}
	}
	printf ("\nFound %d Achilles out of %d tested numbers\n",Sum,COMPUTATIONS);
}
