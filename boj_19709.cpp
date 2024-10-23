#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecNum(iK, 0);
	for (int i = 0;i < iK;++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin(), vecNum.end());

	int iAns = 0;
	for (int i = 0;i < iK;++i)
	{
		if (vecNum[i] <= iN)
		{
			iN -= vecNum[i];
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
