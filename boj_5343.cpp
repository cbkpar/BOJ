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

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strWord;
		cin >> strWord;

		int iAns = 0;

		int iCount = 0;
		int iLen = strWord.length();
		for(int i=0;i<iLen;++i)
		{
			if ((i + 1) % 8 == 0)
			{
				if (strWord[i] - '0' != iCount % 2) ++iAns;
				iCount = 0;
			}
			else
			{
				iCount += strWord[i] - '0';
			}
		}
		cout << iAns << "\n";
	}
	return 0;
}
