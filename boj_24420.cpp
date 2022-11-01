#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iMax = 0;
	int iMin = 2147483647;

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iNumber;
		cin >> iNumber;
		iSum += iNumber;
		if (iNumber < iMin)
		{
			iMin = iNumber;
		}
		if (iNumber > iMax)
		{
			iMax = iNumber;
		}
	}
	cout << (iSum - iMax - iMin) << "\n";
	return 0;
}
