#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	int** mapPresum = new int* [iN + 1];
	for (int i = 0; i <= iN; ++i)
	{
		mapPresum[i] = new int[iM + 1];
		for (int j = 0; j <= iM; ++j)
		{
			mapPresum[i][j] = 0;
		}
	}
	for (int i = 1; i <= iN; ++i)
	{
		string strInput;
		cin >> strInput;
		for (int j = 1; j <= iM; ++j)
		{
			if (((i + j) % 2 == 0 && strInput[j - 1] == 'W')
				|| ((i + j) % 2 == 1 && strInput[j - 1] == 'B'))
			{
				++mapPresum[i][j];
				if (i + 8 <= iN)
				{
					--mapPresum[i + 8][j];
				}
				if (j + 8 <= iM)
				{
					--mapPresum[i][j + 8];
				}
				if (i + 8 <= iN && j + 8 <= iM)
				{
					++mapPresum[i + 8][j + 8];
				}
			}
		}
	}
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			mapPresum[i][j] += mapPresum[i - 1][j] + mapPresum[i][j - 1] - mapPresum[i - 1][j - 1];
		}
	}
	int iAnswer = 64;
	for (int i = 8; i <= iN; ++i)
	{
		for (int j = 8; j <= iM; ++j)
		{
			if (mapPresum[i][j] > 32)
			{
				if (iAnswer > 64 - mapPresum[i][j])
				{
					iAnswer = 64 - mapPresum[i][j];
				}
			}
			else
			{
				if (iAnswer > mapPresum[i][j])
				{
					iAnswer = mapPresum[i][j];
				}
			}
		}
	}
	cout << iAnswer << endl;
	return 0;
}
