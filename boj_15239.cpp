#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string strSet = "+_)(*&^%$#@!./,;{}";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		string strWord;
		cin >> strWord;

		bool bLower = false;
		bool bUpper = false;
		bool bDigit = false;
		bool bSpecial = false;

		for (int i = 0;i < iN;++i)
		{
			if (strWord[i] >= 'a' && strWord[i] <= 'z') bLower = true;
			if (strWord[i] >= 'A' && strWord[i] <= 'Z') bUpper = true;
			if (strWord[i] >= '0' && strWord[i] <= '9') bDigit = true;
			for (char ch : strSet)
			{
				if (strWord[i] == ch) bSpecial = true;
			}
		}

		if (bLower && bUpper && bDigit && bSpecial && iN >= 12)
		{
			cout << "valid" << "\n";
		}
		else
		{
			cout << "invalid" << "\n";
		}
	}
	return 0;
}
