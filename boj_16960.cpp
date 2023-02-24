#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecLamp(iM + 1, 0);
	vector<vector<int>> matInput(iN);
	for (int i = 0; i < iN; ++i)
	{
		int iK;
		cin >> iK;
		matInput[i] = vector<int>(iK, 0);
		for (int j = 0; j < iK; ++j)
		{
			cin >> matInput[i][j];
			++vecLamp[matInput[i][j]];
		}
	}

	for (int i = 0; i < iN; ++i)
	{
		bool bNeed = false;
		for (int iNum : matInput[i])
		{
			if (vecLamp[iNum] <= 1)
			{
				bNeed = true;
				break;
			}
		}
		if (!bNeed)
		{
			cout << "1\n";
			return 0;
		}
	}

	cout << "0\n";
	return 0;
}
