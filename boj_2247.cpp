#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSum = 0;

	for (int i = 2; i < iN; ++i)
	{
		int iTemp = (iN / i - 1) * (i);
		iSum = (iSum + iTemp) % 1000000;
	}

	cout << iSum << "\n";
	return 0;
}
