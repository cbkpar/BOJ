#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;

	string strAns = "";
	for (int i = 0;i < 17;++i)
	{
		string strTemp = "";
		int iLen = strAns.length();
		strAns.resize(iLen * 2 + 1);
		int iNow = 0;

		strAns[iLen] = '0';
		for (int j = iLen - 1;j >= 0;--j)
		{
			if (strAns[j] == '1')
			{
				strAns[iLen + 1 + iNow++] = '0';
			}
			else
			{
				strAns[iLen + 1 + iNow++] = '1';
			}
		}
	}

	for (int t = 1;t <= iT;++t)
	{
		int iK;
		cin >> iK;
		cout << "Case #" << t << ": " << strAns[iK - 1] << "\n";
	}

	return 0;
}
