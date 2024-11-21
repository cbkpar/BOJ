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

	vector<int> vecCount(1001, 0);
	for (int i = 1;i <= 1000;++i)
	{
		int iSum = i;
		for (int j = i + 1;j <= 1000;++j)
		{
			iSum += j;
			if (iSum > 1000) break;
			vecCount[iSum]++;
		}
	}

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;
		cout << vecCount[iN] << "\n";
	}
	return 0;
}
