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

	vector<int> vecNum(101, 0);
	for (int i = 1;i <= 100;++i)
	{
		vecNum[i] = i;
	}

	int iN;
	cin >> iN;
	while (iN--> 0)
	{
		string strCommand;
		cin >> strCommand;

		int iNum;
		cin >> iNum;

		for (int i = 1;i <= 100;++i)
		{
			if (vecNum[i] == -1) continue;
			if (strCommand == "ADD")
			{
				vecNum[i] += iNum;
			}
			if (strCommand == "SUBTRACT")
			{
				vecNum[i] -= iNum;
				if (vecNum[i] < 0) vecNum[i] = -1;
			}
			if (strCommand == "MULTIPLY")
			{
				vecNum[i] *= iNum;
			}
			if (strCommand == "DIVIDE")
			{
				if (vecNum[i] % iNum != 0)
				{
					vecNum[i] = -1;
				}
				else
				{
					vecNum[i] /= iNum;
				}
			}
		}
	}

	int iAns = 0;
	for (int i = 1;i <= 100;++i)
	{
		if (vecNum[i] == -1)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
