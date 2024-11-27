#include <stdio.h>
#include <stdlib.h>

#define STUDENTNUM 4

struct student{
	int ID;
	int score;
};

void main(void){
	
	struct student s[STUDENTNUM];
	
	int i;
	int sum;
	int max;
	int maxID;
	double avg;
	
	 
	sum = 0;
	for(i=0; i<STUDENTNUM; i++){
		printf("Input the ID: ");
		scanf("%d", &s[i].ID);
		
		printf("Input the score: ");
		scanf("%d", &s[i].score);
		sum += s[i].score;
		
		printf("\n");
	}
	
	//최대 계산 
	max = 0;
	maxID = 0;
	max = s[0].score;
	maxID = s[0].ID;
	for(i=0; i<STUDENTNUM; i++)
	{
		if (max < s[i].score)
		{
			max = s[i].score;
			maxID = s[i].ID;
		}
	}
	avg = sum/STUDENTNUM;
	printf("The average of the score: %f\n", avg);
	printf("The highest score - ID: %d, score: %d", maxID, max);
}
