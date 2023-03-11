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

	int iN;
	cin >> iN;

	map<int, int> mapRoute;
	for (int i = 0; i < iN; ++i)
	{
		int iS, iE;
		string strDir;
		cin >> iS >> strDir >> iE;
		if (strDir[0] == 'L')
		{
			iE = iS - iE;
		}
		else
		{
			iE = iS + iE;
		}
		mapRoute.insert({ iS,iE });
	}
	int iStart;
	cin >> iStart;
	while (mapRoute.find(iStart) != mapRoute.end())
	{
		iStart = (*mapRoute.find(iStart)).second;
	}
	cout << iStart << "\n";

	return 0;
}
