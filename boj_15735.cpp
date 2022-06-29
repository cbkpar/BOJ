#include <iostream>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	long long lCount = 0;
	for (int i = 1; i <= iN; ++i)
	{
		lCount += (iN - i + 1) * (iN - i + 2) / 2;
		if (i % 2 == 0)
		{
			lCount += (iN - i + 1) * (iN - i + 2) / 2;
		}
	}
	cout << lCount << endl;
	return 0;
}
