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
	vector<long long> vecPos(iN);
	for (int i = 0; i < iN; ++i) cin >> vecPos[i];

	long long lAns = 0;
	for (int i = 1; i < iN; ++i)
	{
		lAns += (vecPos[i] - vecPos[i - 1]) * (vecPos[i] - vecPos[i - 1]);
	}
	cout << lAns << "\n";
	return 0;
}
