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

	int iScore = 0;
	for (int i = 0; i < 8; ++i)
	{
		string strMap;
		cin >> strMap;
		for (int j = 0; j < 8; ++j)
		{
			if (strMap[j] == 'P') iScore += 1;
			if (strMap[j] == 'N') iScore += 3;
			if (strMap[j] == 'B') iScore += 3;
			if (strMap[j] == 'R') iScore += 5;
			if (strMap[j] == 'Q') iScore += 9;
			if (strMap[j] == 'p') iScore -= 1;
			if (strMap[j] == 'n') iScore -= 3;
			if (strMap[j] == 'b') iScore -= 3;
			if (strMap[j] == 'r') iScore -= 5;
			if (strMap[j] == 'q') iScore -= 9;
		}
	}

	cout << iScore << "\n";
	return 0;
}
