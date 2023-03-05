#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iN, iM, iK;
	cin >> iN >> iM >> iK;
	vector<vector<int>> matPresum(iN + 1, vector<int>(iM + 1, 0));
	for (int i = 1; i <= iN; ++i)
	{
		string strInput;
		cin >> strInput;
		for (int j = 1; j <= iM; ++j)
		{
			if (((i + j) % 2 == 0 && strInput[j - 1] == 'W')
				|| ((i + j) % 2 == 1 && strInput[j - 1] == 'B'))
			{
				++matPresum[i][j];
				if (i + iK <= iN) --matPresum[i + iK][j];
				if (j + iK <= iM) --matPresum[i][j + iK];
				if (i + iK <= iN && j + iK <= iM) ++matPresum[i + iK][j + iK];
			}
		}
	}
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = 1; j <= iM; ++j)
		{
			matPresum[i][j] += matPresum[i - 1][j] + matPresum[i][j - 1] - matPresum[i - 1][j - 1];
		}
	}
	int iAnswer = iK * iK;
	int iHalf = iAnswer / 2;
	for (int i = iK; i <= iN; ++i)
	{
		for (int j = iK; j <= iM; ++j)
		{
			if (matPresum[i][j] > iHalf)
			{
				if (iAnswer > iK * iK - matPresum[i][j])
				{
					iAnswer = iK * iK - matPresum[i][j];
				}
			}
			else
			{
				if (iAnswer > matPresum[i][j])
				{
					iAnswer = matPresum[i][j];
				}
			}
		}
	}
	cout << iAnswer << endl;
	return 0;
}
