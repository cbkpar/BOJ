#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iS, iP;
	cin >> iS >> iP;
	string strDNA;
	cin >> strDNA;
	int arrNeedDNA[4] = { 0, };
	for (int i = 0; i < 4; ++i)
	{
		cin >> arrNeedDNA[i];
	}
	int arrNowDNA[4] = { 0, };
	for (int i = 0; i < iP; ++i)
	{
		switch (strDNA[i])
		{
		case 'A':
			++arrNowDNA[0];
			break;
		case 'C':
			++arrNowDNA[1];
			break;
		case 'G':
			++arrNowDNA[2];
			break;
		case 'T':
			++arrNowDNA[3];
			break;
		}
	}
	int iSum = 0;
	if ((arrNowDNA[0] >= arrNeedDNA[0])
		&& (arrNowDNA[1] >= arrNeedDNA[1])
		&& (arrNowDNA[2] >= arrNeedDNA[2])
		&& (arrNowDNA[3] >= arrNeedDNA[3]))
	{
		++iSum;
	}
	for (int i = iP; i < iS; ++i)
	{
		switch (strDNA[i - iP])
		{
		case 'A':
			--arrNowDNA[0];
			break;
		case 'C':
			--arrNowDNA[1];
			break;
		case 'G':
			--arrNowDNA[2];
			break;
		case 'T':
			--arrNowDNA[3];
			break;
		}
		switch (strDNA[i])
		{
		case 'A':
			++arrNowDNA[0];
			break;
		case 'C':
			++arrNowDNA[1];
			break;
		case 'G':
			++arrNowDNA[2];
			break;
		case 'T':
			++arrNowDNA[3];
			break;
		}
		if ((arrNowDNA[0] >= arrNeedDNA[0])
			&& (arrNowDNA[1] >= arrNeedDNA[1])
			&& (arrNowDNA[2] >= arrNeedDNA[2])
			&& (arrNowDNA[3] >= arrNeedDNA[3]))
		{
			++iSum;
		}
	}
	cout << iSum << endl;
	return 0;
}
