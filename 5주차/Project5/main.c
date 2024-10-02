#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int su1, su2;
	
	printf("Input two integer: ");
	scanf("%i %i", &su1, &su2);
	
	printf("& result is %i \n", su1 & su2);
	printf("| result is %i \n", su1 | su2);
	printf("^ result is %i \n", su1 ^ su2);
	printf("<<1 result is %i \n", su1 <<1 );
	printf(">>1 result is %i \n", su1 >>1 );

	
	return 0;
}
