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
		cin >> strWord;

		if (strWord == "0") break;

		bool bZero = strWord[0] == '0' ? true : false;
		int iCount = 1;

		int iSize = strWord.length();
		for (int i = 1; i < iSize; ++i)
		{
			if (strWord[i] == strWord[i - 1])
			{
				++iCount;
			}
			else
			{
				cout << iCount << (bZero ? "0" : "1");
				iCount = 1;
				bZero = !bZero;
			}
		}
		cout << iCount << (bZero ? "0" : "1") << "\n";
	}

	return 0;
}
