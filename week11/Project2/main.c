#include <stdio.h>



int main(void) {
	
	int i = 0;
	char str[4];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	
	while((str[i] != 0))
	{
		printf("%c\n", str[i]);
		i++;
	}

	
	return 0;
}
