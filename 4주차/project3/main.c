#include <stdio.h>
#include <stdlib.h>


int main(void) {
	
	char c;
	
	printf("enter a character: ");
	scanf("%c", &c);
	
	printf("The next character of %c (%d) is %c (%d)", c, c, c+1, c+1 );
	
	return 0;
}
