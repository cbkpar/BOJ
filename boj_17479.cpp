#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	map<string, int> mapNormal;
	map<string, int> mapSpecial;
	set<string> setService;

	while (iA--)
	{
		string strName;
		int iCost;
		cin >> strName >> iCost;
		mapNormal.insert({ strName, iCost });
	}
	while (iB--)
	{
		string strName;
		int iCost;
		cin >> strName >> iCost;
		mapSpecial.insert({ strName, iCost });
	}
	while (iC--)
	{
		string strName;
		cin >> strName;
		setService.insert(strName);
	}

	int iN;
	cin >> iN;

	long long lTotalCostA = 0;
	int iCountA = 0;
	long long lTotalCostB = 0;
	int iCountB = 0;
	int iCountC = 0;
	while (iN--)
	{
		string strName;
		cin >> strName;
		if (mapNormal.find(strName) != mapNormal.end())
		{
			++iCountA;
			lTotalCostA += (*(mapNormal.find(strName))).second;
		}
		else if (mapSpecial.find(strName) != mapSpecial.end())
		{
			lTotalCostB += (*(mapSpecial.find(strName))).second;
			++iCountB;

		}
		else if (setService.find(strName) != setService.end())
		{
			++iCountC;
		}
	}
	if (iCountB > 0 && lTotalCostA < 20000)
	{
		cout << "No\n";
		return 0;
	}
	if (iCountC > 0 && lTotalCostA + lTotalCostB < 50000)
	{
		cout << "No\n";
		return 0;
	}
	if (iCountC > 1)
	{
		cout << "No\n";
		return 0;
	}
	cout << "Okay\n";
	return 0;
}
