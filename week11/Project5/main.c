#include <stdio.h>
#include <stdlib.h>


void main(void) {
	
	char str1[100];
	char str2[100];
	char str3[100];
	
	
	FILE *fp;
	fp = fopen("sample.txt", "w");
	
	printf("input a word: ");
	scanf("%s", &str1);
	fprintf(fp, "%s\n", str1);
	
	printf("input a word: ");
	scanf("%s", &str2);
	fprintf(fp, "%s\n", str2);
	
	printf("input a word: ");
	scanf("%s", &str3);
	fprintf(fp, "%s\n", str3);
	
	
	fclose(fp);
	 
}

