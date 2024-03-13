#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrWeight[7] = { 100,50,20,10,5,2,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSum = 0;
	for (int i = 0;i < iN;++i)
	{
		int iWeight;
		cin >> iWeight;
		if (iSum <= 0)
		{
			iSum += iWeight;
		}
		else
		{
			iSum -= iWeight;
		}
	}

	if (iSum < 0) iSum *= -1;

	int iCount = 0;
	for (int i = 0;i < 7;++i)
	{
		iCount += iSum / arrWeight[i];
		iSum %= arrWeight[i];
	}

	cout << iCount << "\n";
	return 0;
}
