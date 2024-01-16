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

		bool bFirst = true;
		char chLast = strWord[0];
		int iCount = 0;

		for (char ch : strWord)
		{
			if (ch == chLast)
			{
				++iCount;
			}
			else
			{
				if (!bFirst) cout << " ";
				cout << iCount << " " << chLast;
				chLast = ch;
				iCount = 1;
				bFirst = false;
			}
		}
		if (!bFirst) cout << " ";
		cout << iCount << " " << chLast << "\n";
	}

	return 0;
}
