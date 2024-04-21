#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iX;
	cin >> iN >> iX;

	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		int iP1, iP2;
		cin >> iP1 >> iP2;

		if (abs(iP1 - iP2) > iX)
		{
			int iP3;
			cin >> iP3;
			iSum += iP3;
		}
		else
		{
			iSum += max(iP1, iP2);
		}
	}
	
	cout << iSum << "\n";
	return 0;
}
