#include <iostream>
#include <memory.h>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	bool* ArrNumber = new bool[(iN * 2) + 1];
	memset(ArrNumber, false, sizeof(bool) * ((iN * 2) + 1));
	
	int iScoreSang = 0;
	int iScoreGeun = 0;
	list<int> listSang;
	list<int> listGeun;

	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		ArrNumber[iNumber] = true;
	}
	for (int i = 1; i <= iN * 2; ++i)
	{
		if (ArrNumber[i])
		{
			listSang.push_back(i);
		}
		else
		{
			listGeun.push_back(i);
		}
	}
	int iNum = 0;
	while (true)
	{
		bool bIsFind = false;
		for (auto iter = listSang.begin(); iter != listSang.end();)
		{
			if (*iter > iNum)
			{
				iNum = *iter;
				bIsFind = true;
				listSang.erase(iter);
				break;
			}
			++iter;
			if (iter == listSang.end())
			{
				iNum = 0;
			}
		}
		if (listSang.size() == 0)
		{
			break;
		}
		for (auto iter = listGeun.begin(); iter != listGeun.end();)
		{
			if (*iter > iNum)
			{
				iNum = *iter;
				bIsFind = true;
				listGeun.erase(iter);
				break;
			}
			++iter;
			if (iter == listGeun.end())
			{
				iNum = 0;
			}
		}
		if (listGeun.size() == 0)
		{
			break;
		}
		if (!bIsFind)
		{
			break;
		}
	}
	cout << listGeun.size() << "\n";
	cout << listSang.size() << "\n";
	return 0;
}
