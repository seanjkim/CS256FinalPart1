
int popCalc(int pop, int birth, int death)
{

	int total = (pop + birth - death);
	return total;
}

int main()
{
	int startingPop = 0;
	int birthRate;
	int deathRate;
	int years;
	int tempPop;

	printf("What is the starting population?\n");
	scanf("%d", &startingPop);
	while(startingPop < 2)
	{
		printf("Invalid input. Please enter a population greater than 2.\n");
		scanf("%d", &startingPop);
	}

	printf("What is the birth rate?\n");
	scanf("%d", &birthRate);
	while(birthRate < 0)
	{
		printf("Invalid input. Please enter only a positive birth rate.\n");
		scanf("%d", &birthRate);
	}

	printf("What is the death rate?\n");
	scanf("%d", &deathRate);
	while(deathRate < 0)
		{
			printf("Invalid input. Please enter only a positive death rate.\n");
			scanf("%d", &deathRate);
		}

	printf("How many years?\n");
	scanf("%d", &years);
	while(years < 1)
		{
			printf("Invalid input. Please enter a number of years greater than 1.\n");
			scanf("%d", &years);
		}
	for(int i = 0; i < years; i++)
	{
		int population = popCalc(startingPop, birthRate, deathRate);
		printf("Year %d population: %d\n", (i + 1), population);
		startingPop = population;
	}
	return 0;
}


