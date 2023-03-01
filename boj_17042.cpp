#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strOrner;
	cin >> strOrner;

	vector<bool> vecVisited(26, false);
	vecVisited[strOrner[0] - 'A'] = true;

	int iN;
	cin >> iN;
	while (iN--)
	{
		string strWinner, strLoser;
		cin >> strWinner >> strLoser;
		if (strLoser[0] == strOrner[0])
		{
			strOrner = strWinner;
			vecVisited[strOrner[0] - 'A'] = true;
		}
	}
	int iCount = 0;
	for (int i = 0; i < 26; ++i) if (vecVisited[i]) ++iCount;

	cout << strOrner << "\n" << iCount << "\n";
	return 0;
}
