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
	long long lX;
	cin >> iN >> lX;

	vector<long long> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	long long lMin = vecNum[0] + vecNum[1];
	for (int i = 1; i < iN; ++i)
	{
		lMin = min(lMin, vecNum[i - 1] + vecNum[i]);
	}
	cout << (lMin* lX) << "\n";
	return 0;
}
