#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;
	int iCount = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum == 1)
		{
			++iCount;
		}
	}

	int iNeed = (iN + 1) / 2 - iCount;
	if (iNeed <= 0)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << iNeed << "\n";
	}
	return 0;
}
