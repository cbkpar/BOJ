#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int iA, int iB)
{
	if (iB % iA == 0) return iA;
	return gcd(iB % iA, iA);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iP, iQ;
	cin >> iN >> iP >> iQ;

	vector<pair<int, int>> vecNum;

	for (int i = 2;i <= iN;++i)
	{
		for (int j = 1;j < i;++j)
		{
			if (gcd(i, j) == 1)
			{
				if (i < j * iP && j * iQ < i)
				{
					vecNum.push_back({ j, i });
				}
			}
		}
	}

	sort(vecNum.begin(), vecNum.end(), [](const pair<int, int>& o1, const pair<int, int>& o2)->bool {
		return o1.first *o2.second < o2.first * o1.second;
		});
	
	for (const pair<int, int>& o1 : vecNum)
	{
		cout << o1.first << "/" << o1.second << "\n";
	}
	return 0;
}
