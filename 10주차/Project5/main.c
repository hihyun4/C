#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3


int main(int argc, char *argv[]) {
	
	int A[ROWS][COLS] = {
		{2,3,0},
		{8,9,1},
		{7,0,5} };
	
	int B[ROWS][COLS] = {
		{1,0,0},
		{0,1,0},
		{0,0,1} };
	
	int C[ROWS][COLS];
	
	int i,j;
	
	addMatrix(A, B, C);
	printMatrix(C);
	
	return 0;
}

int addMatrix(int a[ROWS][COLS], int b[ROWS][COLS], int c[ROWS][COLS]){
	
	int i, j;
	
	for (i = 0; i<ROWS; i++)
	{
		for (j = 0; j<COLS; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

int printMatrix(int a[ROWS][COLS])
{
	int i;
	for (i = 0; i<ROWS; i++)
	{
		printf("%d %4d %4d\n", a[i][0], a[i][1], a[i][2]);
	}
}

