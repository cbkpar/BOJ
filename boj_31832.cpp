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

	vector<string> vecName(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecName[i];
	}

	string strAns = "";
	for (int i = 0;i < iN;++i)
	{
		if (vecName[i].length() > 10)
		{
			continue;
		}

		int iCountUpper = 0;
		int iCountDown = 0;
		int iCountDigit = 0;
		int iCountOther = 0;

		for (char ch : vecName[i])
		{
			if (ch >= 'a' && ch <= 'z')
			{
				++iCountDown;
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				++iCountUpper;
			}
			else if (ch >= '0' && ch <= '9')
			{
				++iCountDigit;
			}
			else
			{
				++iCountOther;
			}
		}

		if (iCountDigit == vecName[i].length())
		{
			continue;
		}

		if (iCountUpper > iCountDown)
		{
			continue;
		}

		strAns = vecName[i];
	}

	cout << strAns << "\n";
	return 0;
}
