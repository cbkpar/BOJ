#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

long long arrPrime[27] = {
6772133,
6428761,
4972207,
254161,
9774467,
1606291,
796373,
3684647,
3017897,
8688083,
4075963,
7207649,
2854003,
7474759,
5608697,
993241,
8814643,
799093,
1831523,
257171,
1199819,
8526949,
7537561,
8778883,
8546749,
8406919,
601309 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWordA, strWordB;
	cin >> strWordA >> strWordB;

	int iLenA = strWordA.length();
	int iLenB = strWordB.length();

	vector<set<long long>> vecSet(iLenA, set<long long>());
	for (int i = 0;i < iLenA;++i)
	{
		long long iSum = 0;
		for (int j = 0;j <= i;++j)
		{
			iSum += arrPrime[(strWordA[j] - 'a')] * arrPrime[(strWordA[j] - 'a') + 1];
		}
		vecSet[i].insert(iSum);
		for (int j = i + 1;j < iLenA;++j)
		{
			iSum -= arrPrime[(strWordA[j - i - 1] - 'a')] * arrPrime[(strWordA[j - i - 1] - 'a') + 1];
			iSum += arrPrime[(strWordA[j] - 'a')] * arrPrime[(strWordA[j] - 'a') + 1];
			vecSet[i].insert(iSum);
		}
	}

	int iAns = 0;
	for (int i = 0;i < iLenB;++i)
	{
		if (i >= iLenA) break;
		long long iSum = 0;
		for (int j = 0;j <= i;++j)
		{
			iSum += arrPrime[(strWordB[j] - 'a')] * arrPrime[(strWordB[j] - 'a') + 1];
		}
		if (vecSet[i].find(iSum) != vecSet[i].end())
		{
			iAns = max(iAns, i + 1);
		}
		for (int j = i + 1;j < iLenB;++j)
		{
			iSum -= arrPrime[(strWordB[j - i - 1] - 'a')] * arrPrime[(strWordB[j - i - 1] - 'a') + 1];
			iSum += arrPrime[(strWordB[j] - 'a')] * arrPrime[(strWordB[j] - 'a') + 1];
			if (vecSet[i].find(iSum) != vecSet[i].end())
			{
				iAns = max(iAns, i + 1);
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
