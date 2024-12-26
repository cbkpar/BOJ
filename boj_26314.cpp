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
	while (iN-- > 0)
	{
		string strWord;
		cin >> strWord;

		int iCountVowel = 0;
		int iCountConso = 0;

		for (char ch : strWord)
		{
			switch (ch)
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				++iCountVowel;
				break;
			default:
				++iCountConso;
				break;
			}
		}

		cout << strWord << "\n";
		cout << (iCountVowel > iCountConso ? "1" : "0") << "\n";
	}

	return 0;
}
