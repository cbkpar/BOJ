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

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		vector<string> vecWord(5, "");
		for (int i = 0;i < 5;++i)
		{
			cin >> vecWord[i];
		}

		int iAns = 0;
		for (int i = 0;i < 5;++i)
		{
			int iTemp = 1;
			for (int j = i + 1;j < 5;++j)
			{
				if (vecWord[i][0] == vecWord[j][0])
				{
					++iTemp;
				}
			}

			iAns = max(iAns, iTemp);
		}
		cout << iAns << "\n";
	}

	return 0;
}
