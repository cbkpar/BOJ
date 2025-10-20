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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[iNum - 1] = i;
	}

	vector<int> vecLast(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		vecLast[i] = vecNum[iNum - 1];
	}

	bool bPossible = true;
	for (int i = 0;i < iN;++i)
	{
		if (vecLast[i] == 0) continue;
		if (vecLast[(i + 1) % iN] != vecLast[i] - 1 && vecLast[(i + iN - 1) % iN] != vecLast[i] - 1)
		{
			bPossible = false;
		}
	}

	if (bPossible)
	{
		cout << "good puzzle" << "\n";
	}
	else
	{
		cout << "bad puzzle" << "\n";
	}
	return 0;
}
