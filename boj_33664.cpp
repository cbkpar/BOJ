#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lB, iN, iM;
	cin >> lB >> iN >> iM;

	map<string, long long> mapItem;
	for (int i = 0; i < iN; ++i)
	{
		string strWord;
		cin >> strWord;

		long long lCost;
		cin >> lCost;

		mapItem[strWord] = lCost;
	}

	long long lSum = 0;
	for (int i = 0; i < iM; ++i)
	{
		string strWord;
		cin >> strWord;
		lSum += mapItem[strWord];
	}

	if (lSum > lB)
	{
		cout << "unacceptable" << "\n";
	}
	else
	{
		cout << "acceptable" << "\n";
	}
	return 0;
}
