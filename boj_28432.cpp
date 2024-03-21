#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	vector<string> vecList(iN, "");
	set<string> setList;
	for (int i = 0;i < iN;++i)
	{
		cin >> vecList[i];
		setList.insert(vecList[i]);
	}

	int iM;
	cin >> iM;
	vector<string> vecWord(iM, "");
	for (int i = 0;i < iM;++i) cin >> vecWord[i];

	for (int i = 0;i < iN;++i)
	{
		if (vecList[i] == "?")
		{
			for (int j = 0;j < iM;++j)
			{
				bool bPossible = true;
				if (i > 0)
				{
					int iLenBefore = vecList[i - 1].length();
					if (vecList[i - 1][iLenBefore - 1] != vecWord[j][0])
					{
						bPossible = false;
					}
				}
				if (i < iN - 1)
				{
					int iLen = vecWord[j].length();
					if (vecList[i + 1][0] != vecWord[j][iLen - 1])
					{
						bPossible = false;
					}
				}
				if (setList.find(vecWord[j]) != setList.end())
				{
					bPossible = false;
				}
				if (bPossible)
				{
					cout << vecWord[j] << "\n";
				}
			}
		}
	}

	return 0;
}
