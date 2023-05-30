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

	while (iN--)
	{
		string strWord;
		getline(cin, strWord);

		int iLength = strWord.length();
		int iCount = 0;

		for (int i = 0; i < iLength - 2; ++i)
		{
			if (strWord[i] == '\\' && strWord[i + 1] == '\\' && strWord[i + 2] == '\'')
			{
				strWord[i] = 'w';
				strWord[i + 1] = ' ';
				strWord[i + 2] = ' ';
				++iCount;
			}
		}
		for (int i = 0; i < iLength - 1; ++i)
		{
			if (strWord[i] == '\\' && strWord[i + 1] == '\'')
			{
				strWord[i] = 'v';
				strWord[i + 1] = ' ';
				++iCount;
			}
		}
		for (int i = 0; i < iLength; ++i)
		{
			if (strWord[i] == '@')
			{
				strWord[i] = 'a';
				++iCount;
			}
			if (strWord[i] == '[')
			{
				strWord[i] = 'c';
				++iCount;
			}
			if (strWord[i] == '!')
			{
				strWord[i] = 'i';
				++iCount;
			}
			if (strWord[i] == ';')
			{
				strWord[i] = 'j';
				++iCount;
			}
			if (strWord[i] == '^')
			{
				strWord[i] = 'n';
				++iCount;
			}
			if (strWord[i] == '0')
			{
				strWord[i] = 'o';
				++iCount;
			}
			if (strWord[i] == '7')
			{
				strWord[i] = 't';
				++iCount;
			}
		}
		string strAns = "";
		for (int i = 0; i < iLength; ++i)
		{
			if (strWord[i] != ' ')
			{
				strAns += strWord[i];
			}
		}
		iLength = strAns.length();
		if (iLength <= iCount * 2)
		{
			cout << "I don't understand\n";
		}
		else
		{
			cout << strAns << "\n";
		}
	}
	return 0;
}
