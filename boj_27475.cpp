#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;

	while (iT--)
	{
		int iN, iM;
		cin >> iN >> iM;
		vector<bool> vecA(101, false);
		vector<bool> vecB(101, false);
		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;
			vecA[iNum] = true;
		}
		for (int i = 0; i < iM; ++i)
		{
			int iNum;
			cin >> iNum;
			vecB[iNum] = true;
		}

		int iAns = 0;
		for (int i = 1; i <= 100; ++i)
		{
			if (vecA[i] && vecB[i])
			{
				++iAns;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
