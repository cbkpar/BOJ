#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

bool map[100][100];

int main()
{
	memset(map, false, sizeof(bool) * 10000);
	int iN, iM;
	cin >> iN >> iM;
	int iSR = -1;
	int iSC = -1;
	int iER = 0;
	int iEC = 0;
	for (int i = 0; i < iN; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < iM; ++j)
		{
			if (str[j] == '#')
			{
				map[i][j] = true;
				if (iSR == -1)
				{
					iSR = i;
					iSC = j;
				}
				iER = i;
				iEC = j;
			}
		}
	}
	for (int i = iSC + 1; i < iEC; ++i)
	{
		if (!map[iSR][i])
		{
			cout << "UP\n";
			return 0;
		}
	}
	for (int i = iSC + 1; i < iEC; ++i)
	{
		if (!map[iER][i])
		{
			cout << "DOWN\n";
			return 0;
		}
	}
	for (int i = iSR + 1; i < iER; ++i)
	{
		if (!map[i][iSC])
		{
			cout << "LEFT\n";
			return 0;
		}
	}
	for (int i = iSR + 1; i < iER; ++i)
	{
		if (!map[i][iEC])
		{
			cout << "RIGHT\n";
			return 0;
		}
	}
	return 0;
}
