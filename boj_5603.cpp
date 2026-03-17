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

	int iN;
	cin >> iN;

	string strLine;
	cin >> strLine;
	
	for (int i = 0;i < iN;++i)
	{
		int iLen = strLine.length();
		string strTemp = "";
		char chBefore = '-';
		int iCount = 0;
		for (int j = 0;j < iLen;++j)
		{
			if (strLine[j] == chBefore)
			{
				++iCount;
			}
			else
			{
				if (iCount != 0)
				{
					strTemp = strTemp + to_string(iCount) + chBefore;
				}
				iCount = 1;
			}
			chBefore = strLine[j];
		}
		if (iCount != 0)
		{
			strTemp = strTemp + to_string(iCount) + chBefore;
		}
		strLine = strTemp;
	}
	cout << strLine << "\n";
	return 0;
}
