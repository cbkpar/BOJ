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
	vector<int> vecTemp(iN);
	for (int i = 0; i < iN; ++i) cin >> vecTemp[i];

	int iD = 0;
	int iT = 100;
	for (int i = 0; i < iN - 2; ++i)
	{
		int iMaxT = max(vecTemp[i], vecTemp[i + 2]);
		if (iMaxT < iT)
		{
			iT = iMaxT;
			iD = i + 1;
		}
	}
	cout << iD << " " << iT << "\n";
	return 0;
}
