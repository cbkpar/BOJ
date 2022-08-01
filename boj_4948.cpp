#include <iostream>
#include <string.h>

using namespace std;

bool bIsPrime[246913];
int AccPrime[246913];

int main()
{
	bIsPrime[0] = bIsPrime[1] = true;
	memset(&bIsPrime, false, sizeof(bool) * 246913);
	for (int i = 2; i*i <= 246913; ++i)
	{
		for (int j = i*i; j <= 246913; j += i)
		{
			bIsPrime[j] = true;
		}
	}
	memset(&AccPrime, 0, sizeof(int) * 246913);
	for (int i = 2; i <= 246912; ++i)
	{
		AccPrime[i] = AccPrime[i - 1];
		if (!bIsPrime[i])
		{
			++AccPrime[i];
		}
	}

	while (true)
	{
		int iN;
		cin >> iN;
		if (0 == iN)
		{
			break;
		}
		cout << AccPrime[iN * 2] - AccPrime[iN] << endl;
	}
	return 0;
}
