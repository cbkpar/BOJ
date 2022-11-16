#include <iostream>

bool bArrNumber[1000002] = { false, };

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	long long lK;
	cin >> iN >> lK;
	for (int i = 0; i < iN; ++i)
	{
		long long lNumber;
		cin >> lNumber;
		if (lNumber % lK == 0 && (lNumber / lK) <= 1000000)
		{
			bArrNumber[(lNumber / lK)] = true;
		}
	}
	for (int i = 1; i <= 1000001; ++i)
	{
		if (!bArrNumber[i])
		{
			cout << (lK * i) << "\n";
			return 0;
		}
	}
	return 0;
}
