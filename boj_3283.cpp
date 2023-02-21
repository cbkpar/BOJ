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
	vector<int> vecCount(iN, 0);
	for (int i = 0; i < 5; ++i)
	{
		string strCode;
		cin >> strCode;
		for (int j = 0; j < iN; ++j)
		{
			if (strCode[j] == '.') ++vecCount[j];
			if (strCode[j] == 'X') --vecCount[j];
		}
	}

	while (true)
	{
		bool bBreak = true;
		for (int i = 0; i < iN; ++i)
		{
			if (i + 1 < iN)
			{
				if (vecCount[i] * vecCount[i + 1] > 0)
				{
					if (i - 1 >= 0 && vecCount[i - 1] == 0)
					{
						vecCount[i - 1] = vecCount[i] * -1;
						bBreak = false;
					}
					if (i + 2 < iN && vecCount[i + 2] == 0)
					{
						vecCount[i + 2] = vecCount[i] * -1;
						bBreak = false;
					}
				}
			}
			if (i + 2 < iN)
			{
				if (vecCount[i] * vecCount[i + 2] > 0)
				{
					if (vecCount[i + 1] == 0)
					{
						vecCount[i + 1] = vecCount[i] * -1;
						bBreak = false;
					}
				}
			}
		}
		if (bBreak) break;
	}

	for (int i = 0; i < iN; ++i)
	{
		if (vecCount[i] == 0)
		{
			cout << "UNDETERMINABLE\n";
			return 0;
		}
	}
	for (int i = 0; i < iN; ++i)
	{
		if (i + 1 < iN)
		{
			if (vecCount[i] * vecCount[i + 1] > 0)
			{
				cout << "1";
				++i;
			}
			else
			{
				cout << "0";
			}
		}
		else
		{
			cout << "0";
		}
	}
	cout << "\n";

	return 0;
}
