#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecA(5, 0);
	vector<int> vecB(5, 0);

	for (int i = 0;i < 5;++i)
	{
		cin >> vecA[i];
	}
	for (int i = 0;i < 5;++i)
	{
		cin >> vecB[i];
	}

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	int iAns = 0;
	for (int i = 0;i < 5;++i)
	{
		if (vecA[i] > vecB[i])
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
