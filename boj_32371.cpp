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

	vector<string> vecLine(4, "");
	for (int i = 0;i < 4;++i)
	{
		cin >> vecLine[i];
	}

	string strWord;
	cin >> strWord;

	int iR = 0;
	int iC = 0;

	for (int i = 0;i < 9;++i)
	{
		for (int j = 0;j < 4;++j)
		{
			for (int k = 0;k < 10;++k)
			{
				if (vecLine[j][k] == strWord[i])
				{
					iR += j;
					iC += k;
				}
			}
		}
	}

	iR /= 9;
	iC /= 9;

	cout << vecLine[iR][iC] << "\n";
	return 0;
}
