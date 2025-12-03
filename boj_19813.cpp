#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 0;i < iN;++i)
	{
		string strDate;
		cin >> strDate;

		bool bDMY = false;
		for (char ch : strDate)
		{
			if (ch == '.')
			{
				bDMY = true;
			}
		}

		vector<int> vecNum;
		int iTemp = 0;
		for (char ch : strDate)
		{
			if(bDMY)
			{
				if (ch == '.')
				{
					vecNum.push_back(iTemp);
					iTemp = 0;
				}
				else
				{
					iTemp *= 10;
					iTemp += ch - '0';
				}
			}
			else
			{
				if (ch == '/')
				{
					vecNum.push_back(iTemp);
					iTemp = 0;
				}
				else
				{
					iTemp *= 10;
					iTemp += ch - '0';
				}
			}
		}
		vecNum.push_back(iTemp);

		int iDay = 0;
		int iMonth = 0;
		int iYear = 0;

		if (bDMY)
		{
			iDay = vecNum[0];
			iMonth = vecNum[1];
			iYear = vecNum[2];
		}
		else
		{
			iMonth = vecNum[0];
			iDay = vecNum[1];
			iYear = vecNum[2];
		}

		printf("%02d.%02d.%04d %02d/%02d/%04d\n",iDay,iMonth,iYear,iMonth,iDay,iYear);
	}

	return 0;

}
