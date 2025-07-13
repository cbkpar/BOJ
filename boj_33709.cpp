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

	int iAns = 0;
	int iTemp = 0;

	string strWord;
	cin >> strWord;
	for (char ch : strWord)
	{
		if (ch >= '0' && ch <= '9')
		{
			iTemp *= 10;
			iTemp += ch - '0';
		}
		else
		{
			iAns += iTemp;
			iTemp = 0;
		}
	}
	iAns += iTemp;

	cout << iAns << "\n";
	return 0;
}
