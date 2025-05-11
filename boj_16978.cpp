#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<long long> tree;
vector<long long> lazy;
vector<long long> arr;

long long init(int start, int end, int idx) {
	if (start == end) return tree[idx] = arr[start];
	int mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}

void update(int l, int r, int start, int end, int idx, long long diff) {
	if (l > end || start > r) return;
	tree[idx] += diff;
	if (start != end)
	{
		int mid = (start + end) >> 1;
		update(l, r, start, mid, idx * 2, diff);
		update(l, r, mid + 1, end, idx * 2 + 1, diff);
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

	arr.resize(iN);
	for (int i = 0; i < iN; ++i)
	{
		cin >> arr[i];
	}

	tree.resize(iN * 4);
	lazy.resize(iN * 4);
	for (int i = 0; i < iN * 4; ++i)
	{
		tree[i] = 0;
		lazy[i] = 0;
	}
	init(0, iN - 1, 1);

	vector<pair<int, long long>> vecCommand1;
	vector<pair<int, tuple<int, int, int>>> vecCommand2;

	int iM;
	cin >> iM;

	int iSize = 0;
	for (int i = 0; i < iM; ++i)
	{
		int iCommand;
		cin >> iCommand;

		if (iCommand == 1)
		{
			int iNum, iV;
			cin >> iNum >> iV;
			vecCommand1.push_back({ iNum - 1, iV });
		}
		else if (iCommand == 2)
		{
			int iNum, iS, iE;
			cin >> iNum >> iS >> iE;
			vecCommand2.push_back({ iNum, make_tuple(iSize++, iS - 1, iE - 1) });
		}
	}

	int iNow = 0;
	sort(vecCommand2.begin(), vecCommand2.end());

	vector<long long> vecAns(iSize, 0);

	for (int i = 0; i < iSize; ++i)
	{
		while (iNow < vecCommand2[i].first)
		{
			int iS = vecCommand1[iNow].first;
			int iE = vecCommand1[iNow].first;
			int iDiff = vecCommand1[iNow].second - arr[iS];
			arr[iS] = vecCommand1[iNow].second;
			update(iS, iE, 0, iN - 1, 1, iDiff);
			++iNow;
		}

		int iS = get<1>(vecCommand2[i].second);
		int iE = get<2>(vecCommand2[i].second);
		int iOrder = get<0>(vecCommand2[i].second);

		vecAns[iOrder] = search(iS, iE, 0, iN - 1, 1);
	}

	for (int i = 0; i < iSize; ++i)
	{
		cout << vecAns[i] << "\n";
	}

	return 0;
}
