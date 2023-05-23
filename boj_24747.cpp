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

	string strAns;
	cin >> strAns;
	for (int t = 1; t <= 7; ++t)
	{
		string strWord;
		cin >> strWord;
		string strTemp = "";
		if (strWord == strAns)
		{
			cout << "WINNER\n";
			break;
		}
		else
		{
			for (int i = 0; i < 5; ++i)
			{
				if (strWord[i] == strAns[i])
				{
					strTemp += "G";
					continue;
				}
				for (int j = 0; j < 5; ++j)
				{
					if (strWord[i] == strAns[j])
					{
						strTemp += "Y";
						break;
					}
					if (j == 4)
					{
						strTemp += "X";
					}
				}
			}
		}
		if (t == 7)
		{
			cout << "LOSER" << "\n";
		}
		else
		{
			cout << strTemp << "\n";
		}
	}

	return 0;
}
