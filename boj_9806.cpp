#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iAns = 0;

	int iN, iP;
	cin >> iN >> iP;
	
	for (int i = 0;i < iN;++i)
	{
		int iTemp = 1;
		int iPower;
		cin >> iPower;

		for (int j = 0;j < iP;++j)
		{
			iTemp *= iPower;
		}
		
		if (iTemp > 0) iAns += iTemp;
	}

	cout << iAns << "\n";
	return 0;
}
