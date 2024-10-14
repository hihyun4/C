#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int su1, count;
	int answer = 50;
	
	count = 0;
	do
	{
		printf("Guess a number:");
		scanf("%i", &su1);
		if(su1<answer)
		{
			printf("Low!\n");
			count++;
		}
		else if(su1>answer)
		{
			printf("High!\n");
			count++;
		}
			
	}while((su1<answer) || (su1>answer));
	
	printf("congratulation! Trials: %i", count);
	
	return 0;
}
