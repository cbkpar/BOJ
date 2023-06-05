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
		int iN;
		cin >> iN;
		vector<int> vecSum(iN + 1, 0);
		for (int i = 1; i <= iN; ++i)
		{
			int iNum;
			cin >> iNum;
			vecSum[i] = vecSum[i - 1];
			if (iNum == 2)
			{
				++vecSum[i];
			}
		}
		int iAns = -1;
		int iCount = vecSum[iN];
		for (int i = 1; i <= iN; ++i)
		{
			if (vecSum[i] * 2 == iCount)
			{
				iAns = i;
				break;
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
