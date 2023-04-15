#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;
vector<long long> arr;

long long init(int start, int end, int idx) {
	if (start == end) return tree[idx] = arr[start];
	int mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}

void update(int start, int end, int idx, int num, long long amount) {
	if (num < start || num > end) return;
	tree[idx] += amount;
	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, idx * 2, num, amount);
		update(mid + 1, end, idx * 2 + 1, num, amount);
	}
}

long long search(int start, int end, int idx, int rank) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	return (rank <= tree[idx * 2] ? search(start, mid, idx * 2, rank) : search(mid + 1, end, idx * 2 + 1, rank - tree[idx * 2]));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	arr.resize(iN);
	tree.resize(iN * 4);
	for (int i = 0; i < iN; ++i) cin >> arr[i];
	init(0, iN - 1, 1);

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iCommand;
		cin >> iCommand;
		if (iCommand == 1)
		{
			int iNum;
			long long lAmount;
			cin >> iNum >> lAmount;
			update(0, iN - 1, 1, iNum - 1, lAmount);
		}
		else
		{
			int iNum;
			cin >> iNum;
			long long lGroup = search(0, iN - 1, 1, iNum);
			cout << (lGroup + 1) << "\n";
		}
	}
	return 0;
}
