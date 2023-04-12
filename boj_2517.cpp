#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecNum(iN);
	vector<int> vecSort(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i].first;
		vecNum[i].second = i;
	}
	sort(vecNum.begin(), vecNum.end());
	for (int i = 0; i < iN; ++i)
	{
		vecSort[vecNum[i].second] = i;
	}

	tree.resize(iN * 4);
	for (int i = 0; i < iN * 4; ++i)
	{
		tree[i] = 0;
	}
	for (int i = 0; i < iN; ++i)
	{
		int iSpeed = vecSort[i];
		int iRank = i + 1 - search(0, iSpeed - 1, 0, iN - 1, 1);
		update(iSpeed, iSpeed, 0, iN - 1, 1, 1);
		cout << iRank << "\n";
	}
	return 0;
}
