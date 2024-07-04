#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT, iD, iM;
	cin >> iT >> iD >> iM;

	vector<int> vecNum(iM + 2, 0);
	for (int i = 1;i <= iM;++i)
	{
		cin >> vecNum[i];
	}
	vecNum[iM + 1] = iD;

	int iDiff = vecNum[1];
	for (int i = 1;i <= iM + 1;++i)
	{
		iDiff = max(iDiff, vecNum[i] - vecNum[i - 1]);
	}

	if (iDiff >= iT)
	{
		cout << "Y" << "\n";
	}
	else
	{
		cout << "N" << "\n";
	}

	return 0;
}
