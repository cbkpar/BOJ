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

	long long lM;
	cin >> lM;

	vector<long long> vecAns;

	long long lTemp = lM;
	for (long long i = 2;i * i <= lM;++i)
	{
		while (lTemp % i == 0)
		{
			vecAns.push_back(i);
			lTemp /= i;
		}
	}
	if (lTemp > 1) 
	{
		vecAns.push_back(lTemp);
	}

	sort(vecAns.begin(), vecAns.end());
	int iSize = vecAns.size();
	cout << iSize << "\n";
	for (int i = 0;i < iSize;++i)
	{
		cout << vecAns[i] << (i == iSize - 1 ? "\n" : " ");
	}

	return 0;
}
