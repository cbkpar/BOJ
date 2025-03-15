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

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (i % 2 == 0)
		{
			if (strWord[i] != 'I')
			{
				++iAns;
			}
		}
		else
		{
			if (strWord[i] != 'O')
			{
				++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
