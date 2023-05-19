#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<bool> vecNum(iN + 1, false);
	vector<bool> vecNumA(iN + 2, false);
	vector<bool> vecNumB(iN + 3, false);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum <= iN)
		{
			vecNum[iNum] = true;
		}
	}
	bool bStraight = true;
	for (int i = 0; i <= iN; ++i)
	{
		if (vecNum[i])
		{
			if (i == 0)
			{
				vecNumA[1] = true;
			}
			else
			{
				vecNumA[0] = true;
				if (bStraight) vecNumA[i + 1] = true;
			}
		}
		else
		{
			bStraight = false;
		}
	}
	bStraight = true;
	for (int i = 0; i <= iN + 1; ++i)
	{
		if (vecNumA[i])
		{
			if (i == 0)
			{
				vecNumB[1] = true;
			}
			else
			{
				vecNumB[0] = true;
				if (bStraight) vecNumB[i + 1] = true;
			}
		}
		else
		{
			bStraight = false;
		}
	}
	for (int i = 0; i <= iN + 3; ++i)
	{
		if (vecNumB[i] == false)
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
