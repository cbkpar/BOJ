#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		string strName;
		cin >> strName;

		int iLen = strName.length();

		bool bIsInfected = true;
		if (strName[0] < 'A' || strName[0] > 'F') bIsInfected = false;
		if (strName[iLen - 1] < 'A' || strName[iLen - 1] > 'F') bIsInfected = false;

		string strTemp = "";
		if (strName[0] == 'A') strTemp += 'A';
		for (int i = 1; i < iLen - 1; ++i)
		{
			if (strName[i - 1] != strName[i])
			{
				strTemp += strName[i];
			}
		}
		if (strName[iLen - 1] == 'C' && strName[iLen - 1] != strName[iLen - 2]) strTemp += 'C';
		if (strTemp != "AFC") bIsInfected = false;
		if (bIsInfected)
		{
			cout << "Infected!\n";
		}
		else
		{
			cout << "Good\n";
		}
	}
	return 0;
}
