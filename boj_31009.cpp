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

	int iN;
	cin >> iN;

	long long lNum = -1;

	vector<long long> vecNum(iN, 0);

	for (int i = 0; i < iN; ++i)
	{
		string strName;
		cin >> strName >> vecNum[i];
		if (strName == "jinju") lNum = vecNum[i];
	}

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i] > lNum) ++iAns;
	}

	cout << lNum << "\n";
	cout << iAns << "\n";
	return 0;
}
