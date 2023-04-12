#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;

void update(int l, int r, int start, int end, int idx, long long t) {
	if (l > end || start > r) return;
	tree[idx] += t;
	if (start != end) {
		int mid = (start + end) / 2;
		update(l, r, start, mid, idx * 2, t);
		update(l, r, mid + 1, end, idx * 2 + 1, t);
	}
}

long long search(int l, int r, int start, int end, int idx) {
	if (l > end || start > r) return 0;
	if (l <= start && end <= r) return tree[idx];
	int mid = (start + end) / 2;
	return search(l, r, start, mid, idx * 2) + search(l, r, mid + 1, end, idx * 2 + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<vector<int>> vecNum(iN, vector<int>());
	while (iM--)
	{
		int iS, iE;
		cin >> iS >> iE;
		vecNum[iS - 1].push_back(iE - 1);
	}
	for (int i = 0; i < iN; ++i)
	{
		sort(vecNum[i].begin(), vecNum[i].end());
	}
	tree.resize(iN * 4);
	for (int i = 0; i < iN * 4; ++i)
	{
		tree[i] = 0;
	}
	long long lAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j : vecNum[i])
		{
			if (j != iN - 1)
			{
				lAns += search(j + 1, iN - 1, 0, iN - 1, 1);
			}
			update(j, j, 0, iN - 1, 1, 1);
		}
	}
	cout << lAns << "\n";
	return 0;
}
