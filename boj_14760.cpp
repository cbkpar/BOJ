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

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;

		vector<string> vecLine(iN, "");
		for (int i = 0; i < iN; ++i)
		{
			cin >> vecLine[i];
		}

		for (int i = 0; i < iN; ++i)
		{
			int iNow = 0;
			bool bFirst = true;
			for (int j = 0; j < iN; ++j)
			{
				if (vecLine[i][j] == 'X')
				{
					++iNow;
				}
				else if (iNow > 0)
				{
					cout << (bFirst ? "" : " ") << iNow;
					iNow = 0;
					bFirst = false;
				}
			}
			if (bFirst)
			{
				cout << iNow;
			}
			else if(iNow > 0)
			{
				cout << " " << iNow;
			}
			cout << "\n";
		}

		for (int i = 0; i < iN; ++i)
		{
			int iNow = 0;
			bool bFirst = true;
			for (int j = 0; j < iN; ++j)
			{
				if (vecLine[j][i] == 'X')
				{
					++iNow;
				}
				else if (iNow > 0)
				{
					cout << (bFirst ? "" : " ") << iNow;
					iNow = 0;
					bFirst = false;
				}
			}
			if (bFirst)
			{
				cout << iNow;
			}
			else if (iNow > 0)
			{
				cout << " " << iNow;
			}
			cout << "\n";
		}

	}

	return 0;
}
