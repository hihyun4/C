#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int su1, su2;
	
	printf("Input two integer: ");
	scanf("%i %i", &su1, &su2);
	
	printf("+ result in %d\n", su1 + su2);
	printf("- result in %d\n", su1 - su2);
	printf("* result in %d\n", su1 * su2);
	printf("/ result in %d\n", su1 / su2);
	printf(" %% result in %d\n", su1 % su2);
	
	
	return 0;
}
