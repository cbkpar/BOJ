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

	int iK, iPos;
	cin >> iK >> iPos;

	string strNum;
	cin >> strNum;
	while (iK--)
	{
		string strTemp = "";
		int iSize = strNum.length();
		for (int i = 0; i < iSize; i+=2)
		{
			int iCount = strNum[i] - '0';
			while (iCount--)
			{
				strTemp += strNum[i + 1];
			}
		}
		strNum = strTemp;
	}
	cout << strNum[iPos] << "\n";
	return 0;
}
