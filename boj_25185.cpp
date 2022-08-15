#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		string strName[4];
		for (int i = 0; i < 4; ++i)
		{
			cin >> strName[i];
		}
		sort(strName, strName + 4);
		bool bIsRest = false;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = i + 1; j < 4; ++j)
			{
				for (int k = j + 1; k < 4; ++k)
				{
					if (strName[i][1] == strName[j][1] && strName[j][1] == strName[k][1])
					{
						if (strName[i][0] + 1 == strName[j][0] && strName[j][0] + 1 == strName[k][0])
						{
							bIsRest = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < 2; ++i)
		{
			if (strName[i] == strName[i + 1] && strName[i + 1] == strName[i + 2])
			{
				bIsRest = true;
			}
		}
		if (strName[0] == strName[1] && strName[2] == strName[3])
		{
			bIsRest = true;
		}
		cout << (bIsRest ? ":)" : ":(") << "\n";
	}
	return 0;
}
