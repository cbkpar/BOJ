#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long lN;
	cin >> lN;

	vector<long long> vecNum(6, 0);
	for (int i = 0;i < 6;++i) cin >> vecNum[i];

	long long lT, lP;
	cin >> lT >> lP;

	long long lTCount = 0;
	for (int i = 0;i < 6;++i)
	{
		lTCount += (vecNum[i] + lT - 1) / lT;
	}

	long long lPCount = lN / lP;
	long long lPRest = lN % lP;

	cout << lTCount << "\n";
	cout << lPCount << " " << lPRest << "\n";
	return 0;
}
