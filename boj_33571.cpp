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

	int iAns = 0;
	string strTemp;
	while (cin >> strTemp)
	{
		for (char ch : strTemp)
		{
			if (ch == 'A') iAns += 1;
			if (ch == 'a') iAns += 1;
			if (ch == 'B') iAns += 2;
			if (ch == 'b') iAns += 1;
			if (ch == 'D') iAns += 1;
			if (ch == 'd') iAns += 1;
			if (ch == 'e') iAns += 1;
			if (ch == 'g') iAns += 1;
			if (ch == 'O') iAns += 1;
			if (ch == 'o') iAns += 1;
			if (ch == 'P') iAns += 1;
			if (ch == 'p') iAns += 1;
			if (ch == 'Q') iAns += 1;
			if (ch == 'q') iAns += 1;
			if (ch == 'R') iAns += 1;
			if (ch == '@') iAns += 1;
		}
	}

	cout << iAns << "\n";
	return 0;
}
