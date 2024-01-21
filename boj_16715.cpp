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

	int iAns = 1;
	int iDigit = iN;

	for (int i = 2; i < iN; ++i)
	{
		int iTemp = iN;
		int iTotal = 0;
		while (iTemp)
		{
			iTotal += iTemp % i;
			iTemp /= i;
		}
		if (iTotal > iAns)
		{
			iAns = iTotal;
			iDigit = i;
		}
	}

	cout << iAns << " " << iDigit << "\n";
	return 0;
}
