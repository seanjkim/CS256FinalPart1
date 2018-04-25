#include <stdio.h>
char board[3][3];
int checkWinner()
{
	if((board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') ||
	        (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') ||
	        (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') ||
	        (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') ||
	        (board[2][0] == 'x' && board[1][1] == 'x' && board[0][2] == 'x') ||
	        (board[1][2] == 'x' && board[0][2] == 'x' && board[2][2] == 'x') ||
	        (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') ||
	        (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x'))
		return 1;
	if((board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') ||
		        (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') ||
		        (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') ||
		        (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') ||
		        (board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == 'o') ||
		        (board[1][2] == 'o' && board[0][2] == 'o' && board[2][2] == 'o') ||
		        (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') ||
		        (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o'))
		return 1;
	else
		return 0;
}
void printBoard()
{
	printf("[%c][%c][%c]\n",board[0][0], board[0][1], board[0][2]);
	printf("[%c][%c][%c]\n",board[1][0], board[1][1], board[1][2]);
	printf("[%c][%c][%c]\n",board[2][0], board[2][1], board[2][2]);
}
int isBoardEmpty()
{
	for(int i = 0; i < sizeof(board); i++)
	{
		for(int j = 0;j < sizeof(board[0]); j++)
		{
			if(board[i][j] != 'o' && board[i][j] != 'x')
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int column = 0;
	int row = 0;
	int whoseTurn = 2;
	while((isBoardEmpty() == 1) && (checkWinner() == 0))
	{
		printBoard();
		if(whoseTurn%2 == 0)
		{
			printf("Player 1 please enter the column and row where you would like to put an 'o'.\n");
			scanf("%d %d", &column, &row);
			column -= 1;
			row -= 1;
			board[column][row] = 'o';
		}
		else
		{
			printf("Player 2 please enter the column and row where you would like to put an 'x'.\n");
			scanf("%d %d", &column, &row);
			column -= 1;
			row -= 1;
			board[column][row] = 'x';
		}
		whoseTurn++;
	}
	if((checkWinner() == 1))
	{
		printBoard();
		printf("Winner!");
	}
	else
		printf("Tie!");
	return 0;
}

