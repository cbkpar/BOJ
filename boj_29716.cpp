#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	cin.ignore();

	int iAns = 0;
	while (iM--)
	{
		string strWord;
		getline(cin, strWord);
		int iCount = 0;
		for (char ch : strWord)
		{
			if (ch >= 'A' && ch <= 'Z') iCount += 4;
			if (ch >= 'a' && ch <= 'z') iCount += 2;
			if (ch >= '0' && ch <= '9') iCount += 2;
			if (ch == ' ') iCount += 1;
		}
		if (iCount <= iN) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
