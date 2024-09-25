#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	float a, b;
	
	printf("enter two integers: ");
	scanf("%f %f", &a, &b);
	
	printf("%f / %f = %f", a, b, a/b);
	
	return 0;
}
