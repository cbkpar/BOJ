#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> matNum(iN, vector<int>(iM, 0));
	for (int i = 0; i < iN; ++i)
	{
		string strLine;
		cin >> strLine;
		for (int j = 0; j < iM; ++j)
		{
			matNum[i][j] = strLine[j] - '0';
		}
	}

	int iAns = 0;

	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iR = i;
			int iC = j;
			int iRR = iN - i - 1;
			int iRC = iM - j - 1;
			if (iRR == iR && iRC == iC)
			{
				if (matNum[iR][iC] != 8)
				{
					cout << "-1" << "\n";
					return 0;
				}
			}
			else
			{
				if (matNum[iR][iC] == 6 && matNum[iRR][iRC] == 6)
				{
					++iAns;
				}
				else if (matNum[iR][iC] == 6 && matNum[iRR][iRC] == 9)
				{
				}
				else if (matNum[iR][iC] == 9 && matNum[iRR][iRC] == 6)
				{
				}
				else if (matNum[iR][iC] == 9 && matNum[iRR][iRC] == 9)
				{
					++iAns;
				}
				else if (matNum[iR][iC] == 7 && matNum[iRR][iRC] == 7)
				{
					++iAns;
				}
				else if (matNum[iR][iC] == 8 && matNum[iRR][iRC] == 8)
				{

				}
				else
				{
					cout << "-1" << "\n";
					return 0;
				}
			}
		}
	}

	iAns /= 2;
	cout << iAns << "\n";
	return 0;
}
