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

	int iK;
	cin >> iK;

	for (int t = 1; t <= iK; ++t)
	{
		int iN;
		cin >> iN;
		cin.ignore();
		vector<string> vecName(iN, "");
		for (int i = 0; i < iN; ++i)
		{
			getline(cin, vecName[i]);
		}
		string strCode;
		cin >> strCode;

		cout << "Data Set " << t << ":\n";
		int iLength = strCode.length();
		for (string strWord : vecName)
		{
			int iIndex = 0;
			int iSize = strWord.length();
			for (int i = 0; i < iSize; ++i)
			{
				char chWord = strWord[i];
				char chCode = strCode[iIndex];

				if (chWord >= 'a' && chWord <= 'z') chWord = chWord - 'a' + 'A';
				if (chCode >= 'a' && chCode <= 'z') chCode = chCode - 'a' + 'A';

				if (chWord == chCode) ++iIndex;
				if (iIndex == iLength)
				{
					cout << strWord << "\n";
					break;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
