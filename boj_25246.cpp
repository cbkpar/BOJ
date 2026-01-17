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

	string strWord;
	cin >> strWord;

	int iLen = strWord.length();
	int iLast = 0;
	for (int i = 0; i < iLen; ++i)
	{
		if (strWord[i] == 'a') iLast = i;
		if (strWord[i] == 'e') iLast = i;
		if (strWord[i] == 'i') iLast = i;
		if (strWord[i] == 'o') iLast = i;
		if (strWord[i] == 'u') iLast = i;
	}

	for (int i = 0; i <= iLast; ++i)
	{
		cout << strWord[i];
	}
	cout << "ntry" << "\n";


	return 0;
}
