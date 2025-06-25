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
	cin.ignore();

	while (iN-- > 0)
	{
		string strLine;
		getline(cin, strLine);

		vector<string> vecWord;
		string strTemp = "";
		for (char ch : strLine)
		{
			if (ch == ' ')
			{
				vecWord.push_back(strTemp);
				strTemp = "";
			}
			else
			{
				strTemp = strTemp + ch;
			}
		}
		vecWord.push_back(strTemp);

		int iAns = 0;
		for (string strWord : vecWord)
		{
			if (strWord == "Franklin") iAns += 100;
			if (strWord == "Grant") iAns += 50;
			if (strWord == "Jackson") iAns += 20;
			if (strWord == "Hamilton") iAns += 10;
			if (strWord == "Lincoln") iAns += 5;
			if (strWord == "Washington") iAns += 1;
		}
		cout << "$" << iAns << "\n";
	}

	return 0;
}
