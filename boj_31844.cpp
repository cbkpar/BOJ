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

	string strMap;
	cin >> strMap;

	int iStart = -1;
	int iBox = -1;
	int iGoal = -1;

	for (int i = 0;i < 10;++i)
	{
		if (strMap[i] == '@') iStart = i;
		if (strMap[i] == '#') iBox = i;
		if (strMap[i] == '!') iGoal = i;
	}

	int iAns = -1;
	if (iStart < iBox && iBox < iGoal)
	{
		iAns = iGoal - iStart - 1;
	}
	if (iStart > iBox && iBox > iGoal)
	{
		iAns = iStart - iGoal - 1;
	}

	cout << iAns << "\n";
	return 0;
}
