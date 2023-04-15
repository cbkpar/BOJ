#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;

long long init(int start, int end, int idx) {
	if (start == end) return tree[idx] = 1;
	int mid = (start + end) / 2;
	return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}

void update(int start, int end, int idx, int rank) {
	--tree[idx];
	if (start != end) {
		int mid = (start + end) / 2;
		rank <= tree[idx * 2] ? update(start, mid, idx * 2, rank) : update(mid + 1, end, idx * 2 + 1, rank - tree[idx * 2]);
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

	tree.resize(40000);
	while (true)
	{
		int iN, iK, iM;
		cin >> iN >> iK >> iM;
		if (iN == 0) break;

		init(0, iN - 1, 1);
		int iIndex = 1;

		for (int i = 0; i < iN; ++i)
		{
			iIndex = (iIndex + (i == 0 ? iM : iK) - 1 + (iN - i - 1)) % (iN - i) + 1;
			long long lNum = search(0, iN - 1, 1, iIndex) + 1;
			update(0, iN - 1, 1, iIndex);
			if (i == iN - 1) cout << lNum << "\n";
		}
	}
	return 0;
}
