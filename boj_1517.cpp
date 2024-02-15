#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecTemp(1000001, 0);

long long Merge(vector<int>& vecNum, int iLeft, int iMid, int iRight)
{
	long long lCount = 0;

	int iLeftIdx = iLeft;
	int iRightIdx = iMid + 1;
	int iIdx = iLeft;

	while (iLeftIdx <= iMid && iRightIdx <= iRight)
	{
		if (vecNum[iLeftIdx] <= vecNum[iRightIdx])
		{
			vecTemp[iIdx++] = vecNum[iLeftIdx++];
		}
		else
		{
			vecTemp[iIdx++] = vecNum[iRightIdx++];
			lCount += iMid - iLeftIdx + 1;
		}
	}

	while (iLeftIdx <= iMid)
	{
		vecTemp[iIdx++] = vecNum[iLeftIdx++];
	}
	while (iRightIdx <= iRight)
	{
		vecTemp[iIdx++] = vecNum[iRightIdx++];

	}

	for (int i = iLeft;i <= iRight;++i)
	{
		vecNum[i] = vecTemp[i];
	}
	return lCount;
}

long long MergeSort(vector<int>& vecNum, int iLeft, int iRight)
{
	long long lCount = 0;

	if (iLeft < iRight)
	{
		int iMid = (iLeft + iRight) / 2;
		lCount += MergeSort(vecNum, iLeft, iMid);
		lCount += MergeSort(vecNum, iMid + 1, iRight);
		lCount += Merge(vecNum, iLeft, iMid, iRight);
	}

	return lCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<int> vecNum(iN, 0);

	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	long long lAns = MergeSort(vecNum, 0, iN - 1);
	cout << lAns << "\n";

	return 0;
}
