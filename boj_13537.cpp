#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;

int upperbound(int idx, int k)
{
	int iSize = tree[idx].size();
	int iLeft = 0;
	int iRight = iSize;
	while (iLeft < iRight)
	{
		int iMid = (iLeft + iRight) >> 1;
		if (tree[idx][iMid] <= k)
		{
			iLeft = iMid + 1;
		}
		else
		{
			iRight = iMid;
		}
	}
	return iRight;
}

void update(int k, int start, int end, int idx, int num) {
	if (k > end || start > k) return;
	tree[idx].push_back(num);
	if (start != end) {
		int mid = (start + end) / 2;
		update(k, start, mid, idx * 2, num);
		update(k, mid + 1, end, idx * 2 + 1, num);
	}
}

int CalcCount(int l, int r, int start, int end, int idx, int k) {
	if (l > end || start > r) return 0;
	if (l <= start && end <= r) return tree[idx].size() - upperbound(idx, k);
	int mid = (start + end) >> 1;
	return CalcCount(l, r, start, mid, idx * 2, k) + CalcCount(l, r, mid + 1, end, idx * 2 + 1, k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	tree = vector<vector<int>>(iN * 4, vector<int>());
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		update(i, 0, iN - 1, 1, iNum);
	}
	for (int i = 0; i < iN * 4; ++i)
	{
		sort(tree[i].begin(), tree[i].end());
	}

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iS, iE, iK;
		cin >> iS >> iE >> iK;

		int iCount = CalcCount(iS - 1, iE - 1, 0, iN - 1, 1, iK);
		cout << iCount << "\n";
	}
	return 0;
}
