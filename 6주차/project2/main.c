#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int su1, su2;
	
	printf("Enter an integer: ");
	scanf("%i", &su1);
	
	if(su1<0)
	{	
		su2 = -su1;
		printf("%i", su2);
	}
	else
		printf("%i", su1);
	
	return 0;
}
