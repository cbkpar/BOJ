#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iLph;
	cin >> iN >> iLph;

	vector<int> vecLine(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecLine[i];
	}
	
	sort(vecLine.begin(), vecLine.end());
	int iAns = 0;
	int iTotal = 0;
	for (int i = 0;i < iN;++i)
	{
		if (iTotal + vecLine[i] <= iLph * 5)
		{
			iTotal += vecLine[i];
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
