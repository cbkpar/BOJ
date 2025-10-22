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
	vector<pair<string, long long>> vecInfo(iN, { "",0 });
	
	long long lMax = 0;
	for (int i = 0;i < iN;++i)
	{
		cin >> vecInfo[i].first >> vecInfo[i].second;
		if (vecInfo[i].first == "pig")
		{
			lMax = max(lMax, vecInfo[i].second);
		}
	}
	
	long long lAns = lMax;
	for (int i = 0;i < iN;++i)
	{
		if (vecInfo[i].first != "pig" && vecInfo[i].second < lMax)
		{
			lAns += vecInfo[i].second;
		}
	}

	cout << lAns << "\n";
	return 0;
}
