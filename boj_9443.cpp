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

	vector<bool> vecVisited(26, false);
	
	int iN;
	cin >> iN;
	while (iN--)
	{
		string strWord;
		cin >> strWord;
		if (strWord[0] >= 'A' && strWord[0] <= 'Z')
		{
			vecVisited[strWord[0] - 'A'] = true;
		}
	}

	int iAns = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (!vecVisited[i]) break;
		++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
