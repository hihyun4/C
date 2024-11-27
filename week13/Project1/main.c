#include <stdio.h>
#include <stdlib.h>

struct student{
	int ID;
	char name[10];
	double grade;
};

int main(void){
	
	struct student s = {0, "h", 0.0};
	
	s.ID = 24;
	strcpy(s.name, "HYUN");
	s.grade = 4.2;
	
	printf("ID: %d\n", s.ID);
	printf("name: %s\n", s.name);
	printf("grade: %f\n", s.grade);
	
}
