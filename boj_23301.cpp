#include <iostream>

using namespace std;

int arrSum[5002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iT;
	cin >> iN >> iT;
	for (int i = 0; i < iN; ++i)
	{
		int iCount;
		cin >> iCount;
		while (iCount--)
		{
			int iStart, iEnd;
			cin >> iStart >> iEnd;
			for (int j = iStart; j < iEnd; ++j)
			{
				++arrSum[j];
			}
		}
	}
	int iIndex = 0;
	int iSum = 0;
	for (int i = 0; i < iT; ++i)
	{
		iSum += arrSum[i];
	}
	int iMaxSum = iSum;
	for (int i = iT; i <= 5000; ++i)
	{
		iSum += arrSum[i];
		iSum -= arrSum[i - iT];
		if (iSum > iMaxSum)
		{
			iMaxSum = iSum;
			iIndex = i - iT + 1;
		}
	}
	cout << iIndex << " " << (iIndex + iT) << "\n";
	return 0;
}
