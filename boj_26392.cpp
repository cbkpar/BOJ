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

	int iN, iR, iC;
	cin >> iN >> iR >> iC;
	while (iN--)
	{
		vector<string> vecLine(iR, "");
		for (int i = 0;i < iR;++i)
		{
			cin >> vecLine[i];
		}
		int iMax = 0;
		int iMin = iR;
		for (int i = 0;i < iR;++i)
		{
			for (int j = 0;j < iC;++j)
			{
				if (vecLine[i][j] == '#')
				{
					iMax = max(iMax, i);
					iMin = min(iMin, i);
				}
			}
		}
		cout << (iMax - iMin) << "\n";

	}
	return 0;
}
