#include <iostream>
#include <string>

using namespace std;

int matNumber[20][20] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strCommand;
	cin >> strCommand;
	int iN;
	cin >> iN;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			cin >> matNumber[i][j];
		}
	}

	if (strCommand[0] == 'L' || strCommand[0] == 'R')
	{
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				switch (matNumber[i][iN - j - 1])
				{
				case 1:
					cout << "1";
					break;
				case 2:
					cout << "5";
					break;
				case 5:
					cout << "2";
					break;
				case 8:
					cout << "8";
					break;
				default:
					cout << "?";
					break;
				}
				cout << (j == iN - 1 ? "\n" : " ");
			}
		}
	}
	else
	{
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iN; ++j)
			{
				switch (matNumber[iN - i - 1][j])
				{
				case 1:
					cout << "1";
					break;
				case 2:
					cout << "5";
					break;
				case 5:
					cout << "2";
					break;
				case 8:
					cout << "8";
					break;
				default:
					cout << "?";
					break;
				}
				cout << (j == iN - 1 ? "\n" : " ");
			}
		}

	}
	return 0;
}
