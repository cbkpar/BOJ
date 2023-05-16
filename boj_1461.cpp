#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecPlus;
	vector<int> vecMinus;

	int iAns = 0;
	int iMax = 0;

	for (int i = 0; i < iN; ++i)
	{
		int iPos;
		cin >> iPos;
		if (iPos > 0)
		{
			vecPlus.push_back(iPos);
		}
		else
		{
			iPos *= -1;
			vecMinus.push_back(iPos);
		}
		iMax = max(iMax, iPos);
	}
	sort(vecPlus.begin(), vecPlus.end(), greater<>());
	sort(vecMinus.begin(), vecMinus.end(), greater<>());

	int iPlusSize = vecPlus.size();
	int iMinusSize = vecMinus.size();

	for (int i = 0; i < iPlusSize; i += iM)
	{
		iAns += vecPlus[i] * 2;
	}
	for (int i = 0; i < iMinusSize; i += iM)
	{
		iAns += vecMinus[i] * 2;
	}
	iAns -= iMax;
	cout << iAns << "\n";
	return 0;
}
