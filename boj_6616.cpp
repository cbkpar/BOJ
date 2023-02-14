#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;

		string strCode;
		cin.ignore();
		getline(cin, strCode);

		int iCount = 0;
		for (char ch : strCode)
		{
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				++iCount;
			}
		}
		string strAns;
		strAns.resize(iCount);
		int iIndex = 0;
		int iPos = 0;
		for (char ch : strCode)
		{
			if (ch >= 'a' && ch <= 'z')
			{
				strAns[iPos] = (char)(ch - 'a' + 'A');
				iPos += iN;
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				strAns[iPos] = ch;
				iPos += iN;
			}
			if (iPos >= iCount)
			{
				++iIndex;
				iPos = iIndex;
			}
		}
		cout << strAns << "\n";
	}

	return 0;
}
