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

	string strLine;
	cin >> strLine;

	int iNow = 0;
	int iAns = 0;

	for (char ch : strLine)
	{
		if (ch == '(') iNow += 1;
		if (ch == '{') iNow += 2;
		if (ch == '[') iNow += 3;

		if (ch == ')') iNow -= 1;
		if (ch == '}') iNow -= 2;
		if (ch == ']') iNow -= 3;

		if (ch >= '0' && ch <= '9')
		{
			iAns = max(iAns, iNow);
		}
	}

	cout << iAns << "\n";
	return 0;
}
