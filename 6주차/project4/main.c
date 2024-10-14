#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	
	int su1, i;
	int sum;
	
	printf("Enter a number: ");
	scanf("%i", &su1);
	
	sum = 0;
	for (i=1; i <= su1; i++)
		sum += i;

	printf("The result is %i", sum);
	
	
	return 0;
}
