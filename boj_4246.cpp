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

	while (true)
	{
		int iN, iM;
		cin >> iN;
		if (iN == 0) break;

		string strWord;
		cin >> strWord;
		int iSize = strWord.length();
		iM = iSize / iN;
		for (int i = 0; i < iN; ++i)
		{
			for (int j = 0; j < iM; ++j)
			{
				if (j % 2 == 0)
				{
					cout << strWord[j * iN + i];
				}
				else
				{
					cout << strWord[j * iN + iN - 1 - i];
				}
			}
		}
		cout << "\n";
	}

	return 0;
}
