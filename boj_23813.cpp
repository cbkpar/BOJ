#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lNumber;
	cin >> lNumber;
	long long lDigit = 999999999;
	while (true)
	{
		if (lNumber > lDigit)
		{
			++lDigit;
			break;
		}
		lDigit /= 10;
	}
	long long lAns = 0;
	long long lTemp = lNumber;
	
	while (true)
	{
		lAns += lTemp;
		long long lRest = lTemp % 10;
		lTemp /= 10;
		lTemp += lRest * lDigit;
		if (lTemp == lNumber)
		{
			break;
		}
	}
	cout << lAns << "\n";
	return 0;
}
