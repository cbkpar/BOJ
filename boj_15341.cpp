#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int CalcNum(string str)
{
	int iSum = 0;
	for (int i = 0;i < 4;++i)
	{
		int iNum = str[i] - '0';
		if (i % 2 == 0)
		{
			iNum *= 2;
		}
		if (iNum > 9) iNum -= 9;
		iSum += iNum;
	}
	return iSum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		vector<string> vecStr(4, "");
		for (int i = 0;i < 4;++i)
		{
			cin >> vecStr[i];
		}
		if (vecStr[0] == "0000" && vecStr[1] == "0000" && vecStr[2] == "0000" && vecStr[3] == "0000")
		{
			break;
		}

		int iAns = 0;
		for (int i = 0;i < 4;++i)
		{
			iAns += CalcNum(vecStr[i]);
		}
		if (iAns % 10 == 0)
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}

	return 0;
}
