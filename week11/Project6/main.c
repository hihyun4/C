#include <stdio.h>
#include <stdlib.h>

/*

//한 글자씩 
void main(void)
{
	FILE *fp = NULL;
	char c;
	fp = fopen("sample.txt", "r");
	
	if(fp == NULL)
		printf("파일 못 열었음\n");
		

	while((c = fgetc(fp)) != EOF)
		putchar(c);
	
		
	fclose(fp);
	
}

*/

//한 단어씩
void main(void)
{
	FILE *fp = NULL;
	int n = 30;
	char c[100];
	fp = fopen("sample.txt", "r");
	
	if(fp == NULL)
		printf("파일 못 열었음\n");
		
	
	while(fgets(c, n, fp) != NULL)
		printf("%s", c);
	
 } 

