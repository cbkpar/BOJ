#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}
	vector<int> vecMax(iN, 99999);

	for (int i = 1;i <= iM;++i)
	{
		if (iM % i == 0)
		{
			for (int j = 0;j < iN;++j)
			{
				vecMax[j] = min(vecMax[j], abs(i - vecNum[j]));
			}
		}
	}
	
	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		iAns += vecMax[i];
	}
	cout << iAns << "\n";
	return 0;
}
