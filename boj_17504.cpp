#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<long long> vecNum(iN);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	long long lA = 1;
	long long lB = vecNum[--iN];
	while (iN--)
	{
		lA += lB * vecNum[iN];
		swap(lA, lB);
	}
	lA = lB - lA;
	cout << lA << " " << lB << "\n";
	return 0;
}
