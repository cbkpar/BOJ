#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	int iIndex = 0;
	int mapPos[2][2];
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			int iNumber;
			cin >> iNumber;
			if (1 == iNumber)
			{
				mapPos[iIndex][0] = i;
				mapPos[iIndex][1] = j;
				++iIndex;
			}
		}
	}
	int iDistance = abs(mapPos[0][0] - mapPos[1][0]) + abs(mapPos[0][1] - mapPos[1][1]);
	cout << iDistance << endl;
	return 0;
}
