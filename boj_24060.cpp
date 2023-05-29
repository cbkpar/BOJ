#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int iN, iK, iAns;

void Merge(vector<int>& vecNum, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 0;
	vector<int> vecTemp(r - p + 1, 0);

	while (i <= q && j <= r)
	{
		if (vecNum[i] <= vecNum[j])
		{
			vecTemp[t++] = vecNum[i++];
		}
		else
		{
			vecTemp[t++] = vecNum[j++];
		}
	}
	while (i <= q) vecTemp[t++] = vecNum[i++];
	while (j <= r) vecTemp[t++] = vecNum[j++];
	
	i = p;
	t = 0;
	while (i <= r)
	{
		vecNum[i++] = vecTemp[t++];
		if (--iK == 0)
		{
			iAns = vecNum[i - 1];
		}
	}
}

void MergeSort(vector<int>& vecNum, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) >> 1;
		MergeSort(vecNum, p, q);
		MergeSort(vecNum, q + 1, r);
		Merge(vecNum, p, q, r);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iN >> iK;
	iAns = -1;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];
	
	MergeSort(vecNum, 0, iN - 1);
	
	cout << iAns << "\n";
	return 0;
}
