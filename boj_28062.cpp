#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iSum = 0;
	vector<int> vecCount;

	while (iN--)
	{
		int iCount;
		cin >> iCount;
		iSum += iCount;

		if (iCount % 2 == 1)
		{
			vecCount.push_back(iCount);
		}
	}
	if (vecCount.size() % 2 == 1)
	{
		sort(vecCount.begin(), vecCount.end());
		iSum -= vecCount[0];
	}
	cout << iSum << "\n";
	return 0;
}
