#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN, iK;
	cin >> iN >> iK;

	int iSum = 0;
	for(int i=0;i<iK;++i)
	{
		int iScore;
		cin >> iScore;
		iSum += iScore;
	}

	cout << (double)(iSum + (iK-iN)*3)/iN << " ";
	cout << (double)(iSum + (iK-iN)*-3)/iN << "\n";
	return 0;
}
