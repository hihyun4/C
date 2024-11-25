#include <stdio.h>
#include <stdlib.h>

char *proverb = "All that glisters is not gold.";

void setPointer(char **q)
{
	*q = proverb;
}

int main(void)
{
	char *p = "zzz";
	setPointer(&p);
	printf("%s\n", p);
	
	return 0;
}

//이중포인터 활용해서 고쳐야함.
