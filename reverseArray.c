#include <stdio.h>

int* copyArray(int array[], int size)
{
	int *arrayptr = &array;
	int copyArray[size];
	int *copyArrayptr = &copyArray;
	for(int i = 0; i < size; i++)
	{
		copyArrayptr++;
	}
	for(int i = 0; i < size; i++)
	{
			*copyArrayptr = *arrayptr;
			copyArrayptr--;
			arrayptr++;
	}
	return copyArrayptr;
}
int main()
{
	int check;

	printf("Creating array of size 9 and filling entries of array equal to its value (1-9). Enter 1 to continue.\n");
	scanf("%d", check);
	while(check != 1)
	{
		printf("Please input 1 to continue.");
		scanf("%d", check);
	}
	int array[10];
	for(int i = 0; i <= 9; i++)
	{
		array[i] = i;
	}

	int* newArray = copyArray(array, sizeof(array));
	for(int i = 0; i < sizeof(array); i++)
	{
		int *tempptr = newArray[i];
		printf("%d", *(tempptr + i));
	}
}
