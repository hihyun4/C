#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	
	int int1;
	printf("Enter an integer: ");
	scanf("%i", &int1);
	
	if (int1>0)
		printf("This is positive number.");
	else if(int1<0)
		printf("This is negative number.");
	else
		printf("This is 0.");
		
		
	
	return 0;
}
