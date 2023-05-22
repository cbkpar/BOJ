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
	vector<string> vecName(iN, "");
	map<string, int> mapName;
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecName[i];
		mapName.insert({ vecName[i], i });
	}
	int iMax = 0;
	string strAns = "";
	for (int i = 0; i < iN; ++i)
	{
		string strName;
		cin >> strName;
		int iNum = mapName[strName] - i;
		if (iNum > iMax)
		{
			iMax = iNum;
			strAns = strName;
		}
	}
	if (iMax == 0)
	{
		cout << "suspicious\n";
	}
	else
	{
		cout << strAns << "\n";
	}
	return 0;
}
