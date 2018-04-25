#include <stdio.h>
char seats[15][30];
float seatPrices[15];
float ticketTotal = 0;
int seatsSold = 0;
int seatsAvailable = 450;
void initializeSeats()
{
	for(int i = 0;i <= 14; i++)
		{
			for(int j = 0; j <= 29; j++)
			{
				seats[i][j] = 'o';
			}
		}
}
void displayTicketTotal()
{
	printf("Total amount made from tickets sold: %f\n", ticketTotal);
}
void purchase()
{
	int row, column;
	printf("Please input the row then column of the seat you would like to purchase.");
	fflush(stdout);
	scanf("%i %i", &row, &column);
	row -= 1;
	column -= 1;

	seatsSold++;
	seatsAvailable--;
	ticketTotal += seatPrices[row];

	printf("Your total is %f\n", seatPrices[row]);
	seats[row][column] = 'x';
}

/*
void updateSeats(int row, int column)
{
	seats[row][column] = 'x';
}
*/
void displaySeats()
{
	printf("\t\t\tSeats\n");
	printf("\t123456789012345678901234567890\n");

	printf("Row 1\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[0][0], seats[0][1], seats[0][2], seats[0][3], seats[0][4], seats[0][5], seats[0][6], seats[0][7], seats[0][8], seats[0][9], seats[0][10], seats[0][11], seats[0][12], seats[0][13], seats[0][14], seats[0][15], seats[0][16], seats[0][17], seats[0][18], seats[0][19], seats[0][20], seats[0][21], seats[0][22], seats[0][23], seats[0][24], seats[0][25], seats[0][26], seats[0][27], seats[0][28], seats[0][29]);
	printf("Row 2\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[1][0], seats[1][1], seats[1][2], seats[1][3], seats[1][4], seats[1][5], seats[1][6], seats[1][7], seats[1][8], seats[1][9], seats[1][10], seats[1][11], seats[1][12], seats[1][13], seats[1][14], seats[1][15], seats[1][16], seats[1][17], seats[1][18], seats[1][19], seats[1][20], seats[1][21], seats[1][22], seats[1][23], seats[1][24], seats[1][25], seats[1][26], seats[1][27], seats[1][28], seats[1][29]);
	printf("Row 3\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[2][0], seats[2][1], seats[2][2], seats[2][3], seats[2][4], seats[2][5], seats[2][6], seats[2][7], seats[2][8], seats[2][9], seats[2][10], seats[2][11], seats[2][12], seats[2][13], seats[2][14], seats[2][15], seats[2][16], seats[2][17], seats[2][18], seats[2][19], seats[2][20], seats[2][21], seats[2][22], seats[2][23], seats[2][24], seats[2][25], seats[2][26], seats[2][27], seats[2][28], seats[2][29]);
	printf("Row 4\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[3][0], seats[3][1], seats[3][2], seats[3][3], seats[3][4], seats[3][5], seats[3][6], seats[3][7], seats[3][8], seats[3][9], seats[3][10], seats[3][11], seats[3][12], seats[3][13], seats[3][14], seats[3][15], seats[3][16], seats[3][17], seats[3][18], seats[3][19], seats[3][20], seats[3][21], seats[3][22], seats[3][23], seats[3][24], seats[3][25], seats[3][26], seats[3][27], seats[3][28], seats[3][29]);
	printf("Row 5\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[4][0], seats[4][1], seats[4][2], seats[4][3], seats[4][4], seats[4][5], seats[4][6], seats[4][7], seats[4][8], seats[4][9], seats[4][10], seats[4][11], seats[4][12], seats[4][13], seats[4][14], seats[4][15], seats[4][16], seats[4][17], seats[4][18], seats[4][19], seats[4][20], seats[4][21], seats[4][22], seats[4][23], seats[4][24], seats[4][25], seats[4][26], seats[4][27], seats[4][28], seats[4][29]);
	printf("Row 6\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[5][0], seats[5][1], seats[5][2], seats[5][3], seats[5][4], seats[5][5], seats[5][6], seats[5][7], seats[5][8], seats[5][9], seats[5][10], seats[5][11], seats[5][12], seats[5][13], seats[5][14], seats[5][15], seats[5][16], seats[5][17], seats[5][18], seats[5][19], seats[5][20], seats[5][21], seats[5][22], seats[5][23], seats[5][24], seats[5][25], seats[5][26], seats[5][27], seats[5][28], seats[5][29]);
	printf("Row 7\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[6][0], seats[6][1], seats[6][2], seats[6][3], seats[6][4], seats[6][5], seats[6][6], seats[6][7], seats[6][8], seats[6][9], seats[6][10], seats[6][11], seats[6][12], seats[6][13], seats[6][14], seats[6][15], seats[6][16], seats[6][17], seats[6][18], seats[6][19], seats[6][20], seats[6][21], seats[6][22], seats[6][23], seats[6][24], seats[6][25], seats[6][26], seats[6][27], seats[6][28], seats[6][29]);
	printf("Row 8\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[7][0], seats[7][1], seats[7][2], seats[7][3], seats[7][4], seats[7][5], seats[7][6], seats[7][7], seats[7][8], seats[7][9], seats[7][10], seats[7][11], seats[7][12], seats[7][13], seats[7][14], seats[7][15], seats[7][16], seats[7][17], seats[7][18], seats[7][19], seats[7][20], seats[7][21], seats[7][22], seats[7][23], seats[7][24], seats[7][25], seats[7][26], seats[7][27], seats[7][28], seats[7][29]);
	printf("Row 9\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[8][0], seats[8][1], seats[8][2], seats[8][3], seats[8][4], seats[8][5], seats[8][6], seats[8][7], seats[8][8], seats[8][9], seats[8][10], seats[8][11], seats[8][12], seats[8][13], seats[8][14], seats[8][15], seats[8][16], seats[8][17], seats[8][18], seats[8][19], seats[8][20], seats[8][21], seats[8][22], seats[8][23], seats[8][24], seats[8][25], seats[8][26], seats[8][27], seats[8][28], seats[8][29]);
	printf("Row 10\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[9][0], seats[9][1], seats[9][2], seats[9][3], seats[9][4], seats[9][5], seats[9][6], seats[9][7], seats[9][8], seats[9][9], seats[9][10], seats[9][11], seats[9][12], seats[9][13], seats[9][14], seats[9][15], seats[9][16], seats[9][17], seats[9][18], seats[9][19], seats[9][20], seats[9][21], seats[9][22], seats[9][23], seats[9][24], seats[9][25], seats[9][26], seats[9][27], seats[9][28], seats[9][29]);
	printf("Row 11\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[10][0], seats[10][1], seats[10][2], seats[10][3], seats[10][4], seats[10][5], seats[10][6], seats[10][7], seats[10][8], seats[10][9], seats[10][10], seats[10][11], seats[10][12], seats[10][13], seats[10][14], seats[10][15], seats[10][16], seats[10][17], seats[10][18], seats[10][19], seats[10][20], seats[10][21], seats[10][22], seats[10][23], seats[10][24], seats[10][25], seats[10][26], seats[10][27], seats[10][28], seats[10][29]);
	printf("Row 12\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[11][0], seats[11][1], seats[11][2], seats[11][3], seats[11][4], seats[11][5], seats[11][6], seats[11][7], seats[11][8], seats[11][9], seats[11][10], seats[11][11], seats[11][12], seats[11][13], seats[11][14], seats[11][15], seats[11][16], seats[11][17], seats[11][18], seats[11][19], seats[11][20], seats[11][21], seats[11][22], seats[11][23], seats[11][24], seats[11][25], seats[11][26], seats[11][27], seats[11][28], seats[11][29]);
	printf("Row 13\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[12][0], seats[12][1], seats[12][2], seats[12][3], seats[12][4], seats[12][5], seats[12][6], seats[12][7], seats[12][8], seats[12][9], seats[12][10], seats[12][11], seats[12][12], seats[12][13], seats[12][14], seats[12][15], seats[12][16], seats[12][17], seats[12][18], seats[12][19], seats[12][20], seats[12][21], seats[12][22], seats[12][23], seats[12][24], seats[12][25], seats[12][26], seats[12][27], seats[12][28], seats[12][29]);
	printf("Row 14\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[13][0], seats[13][1], seats[13][2], seats[13][3], seats[13][4], seats[13][5], seats[13][6], seats[13][7], seats[13][8], seats[13][9], seats[13][10], seats[13][11], seats[13][12], seats[13][13], seats[13][14], seats[13][15], seats[13][16], seats[13][17], seats[13][18], seats[13][19], seats[13][20], seats[13][21], seats[13][22], seats[13][23], seats[13][24], seats[13][25], seats[13][26], seats[13][27], seats[13][28], seats[13][29]);
	printf("Row 15\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", seats[14][0], seats[14][1], seats[14][2], seats[14][3], seats[14][4], seats[14][5], seats[14][6], seats[14][7], seats[14][8], seats[14][9], seats[14][10], seats[14][11], seats[14][12], seats[14][13], seats[14][14], seats[14][15], seats[14][16], seats[14][17], seats[14][18], seats[14][19], seats[14][20], seats[14][21], seats[14][22], seats[14][23], seats[14][24], seats[14][25], seats[14][26], seats[14][27], seats[14][28], seats[14][29]);
}
int main()
{
	printf("Welcome to the Theater Ticket System!\n");
	for(int i = 0; i < 15; i++)
	{
		printf("Enter individual price to charge for Row %i: ", i+1);
		fflush(stdout);
		scanf("%f", &seatPrices[i]);
	}
	initializeSeats();

	int menu = 0;
	int decision;
	while(menu == 0)
	{
		displaySeats();
		printf("Seats marked by 'o' are available.\n");
		printf("*****Ticket Management Menu*****\n");
		printf("Enter 1 if you would like to purchase a ticket.\n");
		printf("Enter 2 if you would like to view the total amount the theater has made from ticket sales.\n");
		printf("Enter 3 if you would like to view how many seats have been sold.\n");
		printf("Enter 4 if you would like to view how many seats are available in each row.\n");
		printf("Enter 5 if you would like to view how many seats are available in the entire theater.\n");
		printf("Enter 6 if you would like to exit.\n");

		fflush(stdout);
		scanf("%i", &decision);

		if(decision == 1)
		{
			purchase();
		}
		if(decision == 2)
		{
			printf("Total amount made from ticket sales: %f\n", ticketTotal);
		}
		if(decision == 3)
		{
			printf("Total number of seats sold: %i", seatsSold);
		}
		if(decision == 4)
		{
			int seatsInRow;
			for(int i = 0; i < 15; i++)
			{
				for(int j = 0; j < 30; j++)
				{
					if(seats[i][j] == 'o')
					{
						seatsInRow++;
					}
				}
				printf("Seats available in row %i: %i\n", i + 1, seatsInRow);
				seatsInRow = 0;
			}
		}
		if(decision == 5)
		{
			printf("Seats available in entire theater: %i\n", seatsAvailable);
		}
		if(decision == 6)
		{
			printf("Goodbye!");
			menu = 1;
		}
	}


	return 0;
}


