#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;

long long init(int start, int end, int idx) {
	if (start == end) return tree[idx] = 0;
	int mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}

void update(int start, int end, int idx, int num) {
	if (num < start || num > end) return;
	tree[idx] += 1;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(start, mid, idx * 2, num);
		update(mid + 1, end, idx * 2 + 1, num);
	}
}

long long search(int left, int right, int start, int end, int idx) {
	if (right < start || left > end) return 0;
	if (left <= start && right >= end) return tree[idx];
	int mid = (start + end) / 2;
	return search(left, right, start, mid, idx * 2) + search(left, right, mid + 1, end, idx * 2 + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN, iM, iK;
		cin >> iN >> iM >> iK;

		tree.resize(iM * 4);
		init(0, iM - 1, 1);

		vector<vector<int>> vecNode(iN, vector<int>());
		while (iK--)
		{
			int iS, iE;
			cin >> iS >> iE;
			vecNode[iS - 1].push_back(iE - 1);
		}
		long long lAns = 0;
		for (int i = 0; i < iN; ++i)
		{
			sort(vecNode[i].begin(), vecNode[i].end());
			for (int iNext : vecNode[i])
			{
				lAns += search(iNext + 1, iM - 1, 0, iM - 1, 1);
				update(0, iM - 1, 1, iNext);
			}
		}
		cout << "Test case " << t << ": " << lAns << "\n";
	}
	return 0;
}
