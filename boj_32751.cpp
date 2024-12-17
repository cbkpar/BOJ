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

	int iA, iB, iC, iD;
	cin >> iA >> iB >> iC >> iD;

	bool bPossible = true;
	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	if (strWord[0] != 'a') bPossible = false;
	if (strWord[iLen-1] != 'a') bPossible = false;

	for (int i = 1;i < iLen;++i)
	{
		if (strWord[i - 1] == strWord[i])
		{
			bPossible = false;
		}
	}

	for (char ch : strWord)
	{
		if (ch == 'a' && --iA < 0) bPossible = false;
		if (ch == 'b' && --iB < 0) bPossible = false;
		if (ch == 'c' && --iC < 0) bPossible = false;
		if (ch == 'd' && --iD < 0) bPossible = false;
	}

	cout << (bPossible ? "Yes" : "No") << "\n";

	return 0;
}
