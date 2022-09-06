#include <iostream>

using namespace std;

int puzzle[9][9][9];

int main()
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

	return 0;
}