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

	int iN, iQ;
	cin >> iN >> iQ;

	string strWord;
	cin >> strWord;

	while (iQ-- > 0)
	{
		int iCommand, iL, iR;
		cin >> iCommand >> iL >> iR;
		--iL;

		if (iCommand == 1)
		{
			int iAns = 1;
			for (int i = iL + 1;i < iR;++i)
			{
				if (strWord[i] != strWord[i - 1])
				{
					++iAns;
				}
			}
			cout << iAns << "\n";
		}
		else if (iCommand == 2)
		{
			for (int i = iL;i < iR;++i)
			{
				strWord[i] = (char)((strWord[i] - 'A' + 1) % 26 + 'A');
			}
		}
	}

	return 0;
}
