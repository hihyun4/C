#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int i;
	int sum = 0;
	int avg = 0;
	int grade[5];
	int (*gptr)[5];
	
	for(i=0; i<5; i++)
	{
		printf("Input value - grade[%i] = ", i);
		scanf("%d", &grade[i]);
	}
	
	gptr = &grade;
	for(i=0; i<5; i++)
	{
		sum += (*gptr)[i];
		printf("grade[%d] = %d\n", i, (*gptr)[i]);
	}
	
	avg = sum / 5;
	printf("average: %d", avg);
	
	return 0;
}
