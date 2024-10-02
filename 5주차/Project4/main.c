#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int year, result;
	
	printf("Input the year: ");
	scanf("%i", &year);
	
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	
	printf("Is the year %d the leap year? %d", year, result );
	
	return 0;
}
