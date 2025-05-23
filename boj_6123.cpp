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

	long long lL, lK;
	cin >> lL >> lK;

	vector<long long> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i] <= lL)
		{
			++iAns;
			lL += lK;
		}
		else
		{
			break;
		}
	}

	cout << iAns << "\n";
	return 0;
}
