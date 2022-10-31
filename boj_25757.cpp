#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	string strGameType;
	cin >> iN >> strGameType;

	set<string> setName;

	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		string strName;
		cin >> strName;
		auto iter = setName.find(strName);
		if (iter == setName.end())
		{
			setName.emplace(strName);
			++iCount;
		}
	}
	long long lGamePlayCount = 1;
	if (strGameType[0] == 'Y')
	{
		lGamePlayCount = iCount;
	}
	else if (strGameType[0] == 'F')
	{
		lGamePlayCount = iCount / 2;
	}
	else if (strGameType[0] == 'O')
	{
		lGamePlayCount = iCount / 3;
	}
	cout << lGamePlayCount << "\n";
	return 0;
}
