#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	int res = 1;
	int i;
	for (i = 1 ; i <= n ; i++)
	{
		res *= i;
	}
		
	return res;
}

int combination(int n, int r)
{
	return factorial(n) / ( factorial(r) * factorial(n-r) );
}

int get_integer() 
{
	int x;
	
	printf("Enter the value: ");
	scanf("%i", &x);
	
	return x;
}

int main(void)
{
	int su1, su2;
	int result;
	
	su1 = get_integer();
	su2 = get_integer();
	
	result = combination(su1, su2);
	
	printf("The result of C(%i, %i) is %i.", su1, su2, result);
	
	return 0;
}
