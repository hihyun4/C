#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int su1, su2;
	char c;
	
	printf("Enter the calculation: ");
	scanf("%i %c %i", &su1, &c, &su2);
	
	if (c=='+')
		printf(" = %i", su1 + su2);
	else if(c=='-')
		printf( "= %i", su1 - su2);
	else if(c=='*')
		printf( "= %i", su1 * su2);
	else if(c=='/')
		printf( "= %i", su1 / su2);
	else if(c=='%')
		printf( "= %i", su1 % su2);
	else
		printf("���ǵ��� ���� �������Դϴ�");
	
	return 0;
}
