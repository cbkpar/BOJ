#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int GCD(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return GCD(iB % iA, iA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<pair<int, int>> vecPair;
	vecPair.push_back({ 1,0 });
	vecPair.push_back({ 1,1 });
	for (int i = 2;i <= iN;++i)
	{
		for (int j = 1;j < i;++j)
		{
			if (GCD(i, j) == 1)
			{
				vecPair.push_back({ i,j });
			}
		}

	}

	sort(vecPair.begin(), vecPair.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool
		{
			return o1.second * o2.first < o2.second * o1.first;
		});

	int iSize = vecPair.size();
	cout << iSize << "\n";
	
	for (int i = 0;i < iSize;++i)
	{
		cout << vecPair[i].second << "/" << vecPair[i].first << "\n";
	}
	return 0;
}
