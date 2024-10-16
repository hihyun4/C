#include <stdio.h>
#include <stdlib.h>


int sumTwo(int a, int b)
{
	int result;
	result = a+b;
	
	return result;
}
int square(int n)
{
	int result;
	result = n*n;
	
	return result;
}
int get_max(int x, int y)
{
	int result;
	if (x > y)
		return x;
	else
		return y;
}


int main(void) {
	
	int su1, su2;
	int result_sum, result_sq, result_max;
	
	printf("Enter the integer: ");
	scanf("%i %i", &su1, &su2);
	
	result_sum = sumTwo(su1, su2);
	result_sq = square(su1);
	result_max = get_max(su1, su2);
	
	printf("Result - Sum: %i, Square: %i, Max: %i", result_sum, result_sq, result_max);
	
	return 0;
}
