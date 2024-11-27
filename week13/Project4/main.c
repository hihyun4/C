#include <stdio.h>
#include <stdlib.h>

struct point{
	int x;
	int y;
};

int getArea(struct point p1, struct point p2)
{
	int xdiff;
	int ydiff;
	
	xdiff = (p2.x)-(p1.x);
	ydiff = (p2.y)-(p1.y);
	
	return xdiff*ydiff;
}


int main(int argc, char *argv[]){
	
	struct point p1, p2;
	int area;
	
	printf("Input the coordinate p1(x, y): ");
	scanf("%d %d", &p1.x, &p1.y);
	printf("Input the coordinate p2(x, y): ");
	scanf("%d %d", &p2.x, &p2.y);
	
	area = 0;
	area = getArea(p1, p2);
	
	printf("Area: %d", area);
}
