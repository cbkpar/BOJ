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

	int iCase = 0;

	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{
		switch (iCase)
		{
		case 0:
			if (ch == '0') iCase = 11;
			if (ch == '1') iCase = 1;
			break;
		case 1:
			if (ch == '0') iCase = 2;
			if (ch == '1') iCase = -1;
			break;
		case 2:
			if (ch == '0') iCase = 3;
			if (ch == '1') iCase = -1;
			break;
		case 3:
			if (ch == '0') iCase = 3;
			if (ch == '1') iCase = 4;
			break;
		case 4:
			if (ch == '0') iCase = 11;
			if (ch == '1') iCase = 5;
			break;
		case 5:
			if (ch == '0') iCase = 6;
			if (ch == '1') iCase = 5;
			break;
		case 6:
			if (ch == '0') iCase = 3;
			if (ch == '1') iCase = 0;
			break;
		case 11:
			if (ch == '0') iCase = -1;
			if (ch == '1') iCase = 0;
			break;
		default:
			break;
		}
	}

	if (iCase == 0 || iCase == 4)
	{
		cout << "SUBMARINE" << "\n";
	}
	else
	{
		cout << "NOISE" << "\n";
	}
	return 0;
}
