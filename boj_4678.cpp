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

	vector<long long> vecNum(64, 0);
	vecNum[0] = 1;
	for (int i = 1; i <= 63; ++i)
	{
		vecNum[i] = vecNum[i - 1] * 2 + 1;
	}

	while (true)
	{
		string strNum;
		cin >> strNum;
		if (strNum == "0")
		{
			break;
		}

		int iLen = strNum.length();
		long long lAns = 0;

		for (int i = 0; i < iLen; ++i)
		{
			lAns += vecNum[iLen - i - 1] * (strNum[i] - '0');
		}
		cout << lAns << "\n";
	}
	return 0;
}
