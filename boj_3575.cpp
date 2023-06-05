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

	string strS1, strS2, strT1, strT2;
	cin >> strS1 >> strS2 >> strT1 >> strT2;

	vector<vector<int>> matCount(26, vector<int>(26, 0));

	int iSize = strS1.length();
	for (int i = 0; i < iSize; ++i)
	{
		++matCount[strS1[i] - 'A'][strS2[iSize - i - 1] - 'A'];
		--matCount[strT1[i] - 'A'][strT2[iSize - i - 1] - 'A'];
	}
	int bPossible = true;
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (matCount[i][j] != 0) bPossible = false;
		}
	}
	cout << (bPossible ? "Yes" : "No") << "\n";
	return 0;
}
