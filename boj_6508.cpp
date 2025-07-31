#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;

		vector<long long> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}

		long long lTemp = 0;
		long long lAns = 0;
		for (int i = iN - 1;i >= 0;--i)
		{
			for (int j = 0;j < i;++j)
			{
				vecNum[j] += vecNum[i];
			}
			lAns += vecNum[i];	
		}
		cout << lAns << "\n";
	}

	return 0;
}
