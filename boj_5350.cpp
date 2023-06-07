#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN, iW;
		cin >> iN >> iW;
		vector<int> vecValue(iW + 1, 0);
		while (iN--)
		{
			int iWeight, iValue;
			cin >> iWeight >> iValue;
			for (int i = iW; i >= iWeight; --i)
			{
				vecValue[i] = max(vecValue[i], vecValue[i - iWeight] + iValue);
			}
		}
		int iMax = 0;
		for (int i = 0; i <= iW; ++i)
		{
			iMax = max(iMax, vecValue[i]);
		}
		cout << iMax << "\n";
	}
	return 0;
}
