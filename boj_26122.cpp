#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iLength;
	cin >> iLength;
	string strWord;
	cin >> strWord;

	bool bIsN = false;
	int iBeforeCount = 0;
	int iCount = 0;
	int iAns = 0;
	for (int i = 0; i < iLength; ++i)
	{
		if (strWord[i] == 'N')
		{
			if (bIsN)
			{
				++iCount;
			}
			else
			{
				iBeforeCount = iCount;
				iCount = 1;
			}
			bIsN = true;
		}
		else
		{
			if (!bIsN)
			{
				++iCount;
			}
			else
			{
				iBeforeCount = iCount;
				iCount = 1;
			}
			bIsN = false;
		}
		if (iAns < (iBeforeCount > iCount ? iCount * 2 : iBeforeCount * 2))
		{
			iAns = (iBeforeCount > iCount ? iCount * 2 : iBeforeCount * 2);
		}
	}
	cout << iAns << "\n";
	return 0;
}
