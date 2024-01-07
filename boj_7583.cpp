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
		string strWord;
		getline(cin, strWord);
		if (strWord == "#") break;

		int iS = 0;
		int iNow = 0;
		int iE = strWord.length();
		while (iS < iE)
		{
			while (iNow < iE)
			{
				if (strWord[iNow] == ' ') break;
				++iNow;
			}
			swap(strWord[iS], strWord[iNow - 1]);
			for (int i = 0;iS + i < iNow - i - 1;++i)
			{
				swap(strWord[iS + i], strWord[iNow - i - 1]);
			}
			iS = ++iNow;
		}
		cout << strWord << "\n";
	}

	return 0;
}
