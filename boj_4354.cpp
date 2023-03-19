#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string strWord;
		cin >> strWord;
		if (strWord == ".") break;

		int iLen = strWord.length();
		vector<bool> Visited(iLen + 1, false);
		int iAns = 1;

		for (int i = iLen; i >= 1; --i)
		{
			if (!Visited[i] && iLen % i == 0)
			{
				int iSplit = i;
				bool bPossible = true;
				for (int k = 0; k < iSplit; ++k)
				{
					for (int j = k + iSplit; j < iLen; j += iSplit)
					{
						if (strWord[j] != strWord[j - iSplit])
						{
							bPossible = false;
							break;
						}
					}
					if (!bPossible) break;
				}
				if (bPossible)
				{
					iAns = max(iAns, iLen / iSplit);
				}
				else
				{
					int iSqrt = (int)sqrt(i);
					for (int j = 1; j <= iSqrt; ++j)
					{
						if (i % j == 0)
						{
							Visited[j] = true;
							Visited[i / j] = true;
						}
					}
				}
			}
		}
		cout << iAns << "\n";
	}

	return 0;
}
