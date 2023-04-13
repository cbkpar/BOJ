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

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;

		vector<int> vecNumY(iN);
		vector<pair<int, int>> vecNum(iN);
		map<int, int> mapY;

		for (int i = 0; i < iN; ++i)
		{
			cin >> vecNum[i].first >> vecNum[i].second;
			vecNumY[i] = vecNum[i].second;
		}
		sort(vecNumY.begin(), vecNumY.end());

		mapY.insert({ vecNumY[0],0 });
		int iIndexY = 1;
		for (int i = 1; i < iN; ++i)
		{
			if (vecNumY[i] != vecNumY[i - 1])
			{
				mapY.insert({ vecNumY[i],iIndexY++ });
			}
		}

		sort(vecNum.begin(), vecNum.end(), [&](const pair<int, int>& o1, const pair<int, int>& o2)->bool
			{
				if (o1.first != o2.first) return o1.first < o2.first;
				return o1.second > o2.second;
			});

		tree.resize(iN * 4);
		for (int i = 0; i < iN * 4; ++i)
		{
			tree[i] = 0;
		}
		long long lAns = 0;
		for (int i = 0; i < iN; ++i)
		{
			int iPos = mapY[vecNum[i].second];
			lAns += search(iPos, iN - 1, 0, iN - 1, 1);
			update(iPos, iPos, 0, iN - 1, 1, 1);
		}
		cout << lAns << "\n";
	}
	return 0;
}
