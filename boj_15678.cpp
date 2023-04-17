#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;
vector<long long> arr;

long long init(int start, int end, int idx) {
	if (start == end) return tree[idx] = arr[start];
	int mid = (start + end) / 2;
	return tree[idx] = max(init(start, mid, idx * 2), init(mid + 1, end, idx * 2 + 1));
}

long long update(int start, int end, int idx, int num, long long amount) {
	if (num < start || num > end) return tree[idx];
	if (start == end) return tree[idx] += amount;
	int mid = (start + end) / 2;
	return tree[idx] = max(update(start, mid, idx * 2, num, amount), update(mid + 1, end, idx * 2 + 1, num, amount));
}

long long search(int left, int right, int start, int end, int idx) {
	if (right < start || left > end) return -1000000000;
	if (left <= start && right >= end) return tree[idx];
	int mid = (start + end) / 2;
	return max(search(left, right, start, mid, idx * 2), search(left, right, mid + 1, end, idx * 2 + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	arr.resize(iN);
	for (int i = 0; i < iN; ++i) cin >> arr[i];

	tree.resize(iN * 4);
	init(0, iN - 1, 1);

	long long lAns = arr[0];
	for (int i = 1; i < iN; ++i)
	{
		long long lSum = search(max(i - iM, 0), i - 1, 0, iN - 1, 1);
		if (lSum > 0)
		{
			update(0, iN - 1, 1, i, lSum);
		}
		else
		{
			lSum = 0;
		}
		lAns = max(lAns, arr[i] + lSum);
	}
	cout << lAns << "\n";
	return 0;
}
