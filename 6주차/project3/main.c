#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int num1;
	char c;
	
	printf("Input a string: ");
	
	while((c=getchar()) != '\n')
	{
		
		if ( c <= 57 && c >= 48 )
			num1 ++;

	}
	
	printf("The number of digits is %i", num1);
	
	return 0;
}
