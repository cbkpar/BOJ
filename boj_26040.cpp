#include <iostream>
#include <string>

using namespace std;

bool bCharacter[26] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	getline(cin, strWord);
	string strChangeWord;
	getline(cin, strChangeWord);
	for (char ch : strChangeWord)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			bCharacter[ch - 'A'] = true;
		}
	}
	for (char ch : strWord)
	{
		if (bCharacter[ch - 'A'])
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				cout << (char)(ch - 'A' + 'a');
			}
			else
			{
				cout << ch;
			}
		}
		else
		{
			cout << ch;
		}
	}
	cout << "\n";
	return 0;
}
