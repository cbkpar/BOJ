#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ArrSang[1000001] = { 0, };
bool Arrprime[1000001] = { false, };

int ConvertSang(int iNum)
{
	int iAns = 0;
	while (iNum)
	{
		iAns += (iNum % 10) * (iNum % 10);
		iNum /= 10;
	}
	return iAns;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 1000000; ++i) ArrSang[i] = i;
	ArrSang[7] = 1;
	for (int i = 10; i <= 1000000; ++i)
	{
		int iNow = i;
		while (true)
		{
			iNow = ConvertSang(iNow);
			if (iNow <= i) break;
		}
		ArrSang[i] = ArrSang[iNow];
	}

	for (int i = 2; i * i <= 1000000; i++) {
		for (int j = i * i; j <= 1000000; j += i) {
			Arrprime[j] = true;
		}
	}

	int iN;
	cin >> iN;

	for (int i = 7; i <= iN; i += 2)
	{
		if (!Arrprime[i] && ArrSang[i] == 1)
		{
			cout << i << "\n";
		}
	}

	return 0;

}
