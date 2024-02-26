#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> vecNum(10000, 1);
	for (int i = 2;i <= 9999;++i)
	{
		vecNum[i] = vecNum[i-1] * i;
		while (vecNum[i] % 10 == 0)
		{
			vecNum[i] /= 10;
		}
		vecNum[i] = vecNum[i] % 100000;
	}

	int iN;
	while (cin >> iN)
	{
		printf("%5d -> %d\n", iN, vecNum[iN]%10);
	}
	return 0;
}
