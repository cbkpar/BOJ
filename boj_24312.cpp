#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSum = 0;
	vector<int> vecWeight(4, 0);
	for (int i = 0; i < 4; ++i)
	{
		cin >> vecWeight[i];
		iSum += vecWeight[i];
	}

	int iDiff = iSum;

	for (int i = 0; i < 16; ++i)
	{
		int iTemp = i;
		int iWeight = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (iTemp % 2 == 1)
			{
				iWeight += vecWeight[j];
			}
			iTemp /= 2;
		}
		iDiff = min(iDiff, abs(iSum - iWeight * 2));
	}


	cout << iDiff << "\n";
	return 0;
}
