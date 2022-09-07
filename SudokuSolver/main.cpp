#include <iostream>

using namespace std;

int puzzle[9][9][9];

void IniPuzzle();
void UpdatePuzzle(int x,int y,int z);
void DisplayPuzzle();
void CheckColumns();
void CheckRows();
// Need Def
void CheckGrid();

int main()
{
	IniPuzzle();

	DisplayPuzzle();
	UpdatePuzzle(4, 2, 3);
	UpdatePuzzle(0, 1, 8);
	UpdatePuzzle(0, 5, 3);
	UpdatePuzzle(3, 4, 3);
	UpdatePuzzle(6, 3, 6);
	UpdatePuzzle(8, 3, 4);
	UpdatePuzzle(6, 7, 3);
	UpdatePuzzle(8, 1, 7);
	UpdatePuzzle(8, 2, 6);
	CheckColumns();
	CheckRows();
	DisplayPuzzle();

	return 0;
}

void IniPuzzle()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				puzzle[i][j][k] = 2;
			}
		}
	}
}

void UpdatePuzzle(int x, int y, int z)
{
	// At location
	for (int i = 0; i < 9; i++)
	{
		if (i == z - 1)
			puzzle[x][y][i] = 1;
		else
			puzzle[x][y][i] = 0;
	}

	// Row
	for (int i = 0; i < 9; i++)
	{
		if (i != y)
			puzzle[x][i][z-1] = 0;
	}

	// Column
	for (int i = 0; i < 9; i++)
	{
		if (i != x)
			puzzle[i][y][z - 1] = 0;
	}

	// 3x3 Grid
	int m = int(x / 3);
	int n = int(y / 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (3 * m + i != x && 3 * n + j != y)
				puzzle[3 * m + i][3 * n + j][z - 1] = 0;
		}
	}
}

void DisplayPuzzle()
{
	for (int k = 0; k < 9; k++)
	{
		cout << endl << "Number: " << k + 1 << endl;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << puzzle[i][j][k];
			}
			cout << endl;
		}
	}
}

void CheckColumns()
{
	int count2s = 0;
	int loc = -1;
	for (int k = 0; k < 9; k++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				if (puzzle[i][j][k] == 2 || puzzle[i][j][k] == 1)
				{
					loc = i;
					if (++count2s > 1 || puzzle[i][j][k] == 1)
					{
						loc = -1;
						count2s = 0;
						break;
					}
				}
			}

			if (loc != -1)
			{
				UpdatePuzzle(loc, j, k + 1);
				loc = -1;
				count2s = 0;
			}
		}
	}
}

// Should be able to combine row and column evals, same code, different order
void CheckRows()
{
	int count2s = 0;
	int loc = -1;
	for (int k = 0; k < 9; k++)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (puzzle[i][j][k] == 2 || puzzle[i][j][k] == 1)
				{
					loc = j;
					if (++count2s > 1 || puzzle[i][j][k] == 1)
					{
						loc = -1;
						count2s = 0;
						break;
					}
				}
			}

			if (loc != -1)
			{
				UpdatePuzzle(i, loc, k + 1);
				loc = -1;
				count2s = 0;
			}
		}
	}
}

void CheckGrid()
{
}
