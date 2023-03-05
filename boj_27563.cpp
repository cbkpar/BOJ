#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;

		int iAns = 1000000000;
		int iSize = strWord.length();
		for (int i = 0; i < iSize - 2; ++i)
		{
			if (strWord[i + 1] == 'O')
			{
				iAns = min(iAns, iSize - 3 + (strWord[i] == 'M' ? 0 : 1) + (strWord[i + 2] == 'M' ? 1 : 0));
			}
		}
		cout << (iAns == 1000000000 ? -1 : iAns) << "\n";

	}
	return 0;
}
