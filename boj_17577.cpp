#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		int iN, iM;
		cin >> iN >> iM;
		if (iN == 0 && iM == 0) break;

		vector<int> vecScore(iN, 0);
		for (int i = 0;i < iM;++i)
		{
			for (int j = 0;j < iN;++j)
			{
				int iNum;
				cin >> iNum;
				vecScore[j] += iNum;
			}
		}
		int iAns = 0;
		
		for (int i = 0;i < iN;++i)
		{
			iAns = max(iAns, vecScore[i]);
		}
		cout << iAns << "\n";
	}

	return 0;
}
