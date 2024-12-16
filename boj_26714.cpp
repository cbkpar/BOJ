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

	int iT = iN / 10;
	int iAns = 0;
	for (int i = 0; i < 10; ++i)
	{
		int iCount = 0;
		for (int j = 0; j < iT; ++j)
		{
			if (strWord[i * iT + j] == 'T')
			{
				++iCount;
			}
		}
		if (iCount == iT)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
