#include <stdio.h>
void main()
{
	int i;
	int j;
	int k;
	double pi = 3.14159;
	printf("Geometry Calculator\n");
	printf("\t1. Calculate the Area of a Circle\n");
	printf("\t2. Calculate the Area of a Rectangle\n");
	printf("\t3. Calculate the Area of a Triangle\n");
	printf("\t4. Quit\n");
	printf("\tEnter your choice (1-4):\n");

	scanf("%d", &i);

	if(i == 1)
	{
		printf("What is the radius of the circle?\n");
		scanf("%d", &j);
		while(j < 0)
		{
			printf("Invalid number. Please enter valid number.\n");
			scanf("%d", &j);
		}
		printf("Area of the circle: %f\n", (pi * j * j));
	}
	if(i == 2)
	{
		printf("What is the length and width of the rectangle?\n");
		scanf("%d %d", &j, &k);
		while(j < 0 || k < 0)
				{
					printf("Invalid number(s). Please enter valid number(s).\n");
					scanf("%d %d", &j, &k);
				}
		printf("Area of the rectangle: %d\n", (j * k));
	}
	if(i == 3)
	{
		printf("What is the base and height of the triangle?\n");
		scanf("%d %d", &j, &k);
		while(j < 0 || k < 0)
		{
			printf("Invalid number(s). Please enter valid number(s).\n");
			scanf("%d %d", &j, &k);
		}
		printf("Area of the triangle: %f\n", (j * k * .5));
	}
	if(i == 4)
	{
		printf("Goodbye!");
	}
}
