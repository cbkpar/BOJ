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

	vector<string> vecWord(13, "");
	for (int i = 1; i <= 12; ++i)
	{
		cin >> vecWord[i];
	}

	bool bSet = false;
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = i + 1; j <= 12; ++j)
		{
			for (int k = j + 1; k <= 12; ++k)
			{
				int iCount = 0;
				for (int t = 0; t < 4; ++t)
				{
					if (vecWord[i][t] == vecWord[j][t] && vecWord[j][t] == vecWord[k][t] && vecWord[k][t] == vecWord[i][t])
					{
						++iCount;
					}
					if (vecWord[i][t] != vecWord[j][t] && vecWord[j][t] != vecWord[k][t] && vecWord[k][t] != vecWord[i][t])
					{
						++iCount;
					}
				}
				if (iCount == 4)
				{
					bSet = true;
					cout << i << " " << j << " " << k << "\n";
				}
			}
		}
	}

	if (!bSet)
	{
		cout << "no sets" << "\n";
	}
	return 0;
}
