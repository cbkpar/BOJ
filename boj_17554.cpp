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
	vector<bool> vecNum(iN + 1, false);
	
	int iNow = 0;
	int iAns = 0;

	int iK;
	cin >> iK;
	for (int i = 0; i < iK; ++i)
	{
		int iNum;
		cin >> iNum;
		for (int j = iNum; j <= iN; j += iNum)
		{
			if (vecNum[j])
			{
				--iNow;
			}
			else
			{
				++iNow;
			}
			vecNum[j] = !vecNum[j];
		}
		iAns = max(iAns, iNow);
	}

	cout << iAns << "\n";
	return 0;
}
