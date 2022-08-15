#include <iostream>
#include <memory.h>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int iN;
	cin >> iN;
	int iA, iB;
	cin >> iA >> iB;

	bool* bIsExist = new bool[8];
	memset(bIsExist, false, sizeof(bool) * 8);
	int iCount = 0;
	map<int, set<int>> mapNumber;
	for (int i = 0; i < iN; ++i)
	{
		int iX, iY;
		cin >> iX >> iY;
		auto iter = mapNumber.find(iX);
		if (iter != mapNumber.end())
		{
			iter->second.emplace(iY);
		}
		else
		{
			set<int> newSet;
			newSet.insert(iY);
			mapNumber.emplace(iX, newSet);
		}
		iter = mapNumber.find(iX);
		bIsExist[1] = (iter->second.find(iY - iB) != iter->second.end());
		bIsExist[6] = (iter->second.find(iY + iB) != iter->second.end());
		auto iter2 = mapNumber.find(iX - iA);
		if(iter2 != mapNumber.end())
		{
			bIsExist[0] = (iter2->second.find(iY - iB) != iter2->second.end());
			bIsExist[3] = (iter2->second.find(iY) != iter2->second.end());
			bIsExist[5] = (iter2->second.find(iY + iB) != iter2->second.end());
		}
		else
		{
			bIsExist[0] = false;
			bIsExist[3] = false;
			bIsExist[5] = false;
		}
		auto iter3 = mapNumber.find(iX + iA);
		if (iter3 != mapNumber.end())
		{
			bIsExist[2] = (iter3->second.find(iY - iB) != iter3->second.end());
			bIsExist[4] = (iter3->second.find(iY) != iter3->second.end());
			bIsExist[7] = (iter3->second.find(iY + iB) != iter3->second.end());
		}
		else
		{
			bIsExist[2] = false;
			bIsExist[4] = false;
			bIsExist[7] = false;
		}
		if (bIsExist[0] && bIsExist[1] && bIsExist[3]) ++iCount;
		if (bIsExist[1] && bIsExist[2] && bIsExist[4]) ++iCount;
		if (bIsExist[3] && bIsExist[5] && bIsExist[6]) ++iCount;
		if (bIsExist[4] && bIsExist[6] && bIsExist[7]) ++iCount;
	}
	cout << iCount << "\n";
	delete[] bIsExist;
	return 0;
}
