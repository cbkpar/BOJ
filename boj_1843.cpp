#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ArrPrime[500001] = { false, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i * i <= 500000; i++) {
		for (int j = i * i; j <= 500000; j += i) {
			ArrPrime[j] = true;
		}
	}
	ArrPrime[0] = ArrPrime[1] = true;

	int iN;
	cin >> iN;

	long long lA = 0;
	long long lB = 0;
	long long lC = 0;

	for (int i = 1; i < iN; ++i)
	{
		if (iN - i * 2 <= 0) break;
		lA += iN - i * 2;
	}

	vector<int> vecNum;
	for (int i = 1; i <= iN; ++i)
	{
		if (iN % i == 0)
		{
			vecNum.push_back(i);
		}
	}
	for (int iA : vecNum)
	{
		for (int iB : vecNum)
		{
			if (iA <= iB && iA + iB <= iN && iN % (iA + iB) == 0) ++lB;
		}
	}

	vector<int> vecPrime;
	for (int i = 2; i <= iN; ++i)
	{
		if (!ArrPrime[i])
		{
			vecPrime.push_back(i);
		}
	}
	for (int iA : vecPrime)
	{
		for (int iB : vecPrime)
		{
			if (iA <= iB && iA + iB <= iN && !ArrPrime[iA + iB]) ++lC;
		}
	}

	cout << lA << "\n";
	cout << lB << "\n";
	cout << lC << "\n";
	return 0;
}
