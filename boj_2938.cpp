#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<vector<int>> vecNum(3);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vecNum[iNum % 3].push_back(iNum);
	}

	int iSize0 = vecNum[0].size();
	int iSize1 = vecNum[1].size();
	int iSize2 = vecNum[2].size();

	bool bFirst = true;

	if (iSize0 == 0)
	{
		if (iSize1 == 0 || iSize2 == 0)
		{
			while (iSize1 > 0)
			{
				cout << (bFirst ? "" : " ") << vecNum[1][--iSize1];
				bFirst = false;
			}
			while (iSize2 > 0)
			{
				cout << (bFirst ? "" : " ") << vecNum[2][--iSize2];
				bFirst = false;
			}
			cout << "\n";
		}
		else
		{
			cout << "-1\n";
		}
	}
	else
	{
		if (iSize0 > iSize1 + iSize2 + 1)
		{
			cout << "-1\n";
		}
		else
		{
			while (iSize1 > 0)
			{
				if (iSize0 > 1)
				{
					cout << (bFirst ? "" : " ") << vecNum[0][--iSize0];
					bFirst = false;
				}
				cout << (bFirst ? "" : " ") << vecNum[1][--iSize1];
				bFirst = false;
			}
			if (iSize0 > 0)
			{
				cout << (bFirst ? "" : " ") << vecNum[0][--iSize0];
				bFirst = false;
			}
			while (iSize2 > 0)
			{
				cout << (bFirst ? "" : " ") << vecNum[2][--iSize2];
				bFirst = false;
				if (iSize0 > 0)
				{
					cout << (bFirst ? "" : " ") << vecNum[0][--iSize0];
					bFirst = false;
				}
			}
			cout << "\n";
		}
	}

	return 0;
}
