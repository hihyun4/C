#include <stdio.h>
#include <stdlib.h>

/*

//�� ���ھ� 
void main(void)
{
	FILE *fp = NULL;
	char c;
	fp = fopen("sample.txt", "r");
	
	if(fp == NULL)
		printf("���� �� ������\n");
		

	while((c = fgetc(fp)) != EOF)
		putchar(c);
	
		
	fclose(fp);
	
}

*/

//�� �ܾ
void main(void)
{
	FILE *fp = NULL;
	int n = 30;
	char c[100];
	fp = fopen("sample.txt", "r");
	
	if(fp == NULL)
		printf("���� �� ������\n");
		
	
	while(fgets(c, n, fp) != NULL)
		printf("%s", c);
	
 } 

