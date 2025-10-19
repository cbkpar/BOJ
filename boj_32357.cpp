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
	
	int iN;
	cin >> iN;
	vector<string> vecWord(iN, "");
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecWord[i];
	}

	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		bool bPossible = true;
		int iLen = vecWord[i].length();
		for (int j = 0; j < iLen / 2; ++j)
		{
			if (vecWord[i][j] != vecWord[i][iLen - 1 - j])
			{
				bPossible = false;
			}
		}
		if (bPossible)
		{
			++iCount;
		}
	}

	int iAns = iCount * (iCount - 1);
	cout << iAns << "\n";
	return 0;
}
