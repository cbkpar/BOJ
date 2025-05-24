#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<int> vecN(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecN[i];
	}

	int iM;
	cin >> iM;
	vector<int> vecM(iM, 0);
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecM[i];
	}

	int iLeftN = 0;
	int iLeftM = 0;
	vector<int> vecAns;

	while (true)
	{
		int iMax = -1;
		int iIndexN = -1;
		int iIndexM = -1;

		for (int i = iLeftN; i < iN; ++i)
		{
			for (int j = iLeftM; j < iM; ++j)
			{
				if (vecN[i] == vecM[j] && vecN[i] > iMax)
				{
					iMax = vecN[i];
					iIndexN = i;
					iIndexM = j;
				}
			}
		}

		if (iMax == -1) break;
		vecAns.push_back(vecN[iIndexN]);
		iLeftN = iIndexN + 1;
		iLeftM = iIndexM + 1;
	}


	int iSize = vecAns.size();
	cout << iSize << "\n";
	if (iSize != 0)
	{
		for (int i = 0; i < iSize; ++i)
		{
			cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
		}
	}
	return 0;
}
