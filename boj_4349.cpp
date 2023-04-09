#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecAns(1001, 1000000000);
	for (int i = 1; i <= 1000; ++i)
	{
		for (int j = 1; j <= 1000; ++j)
		{
			if (i * j > 1000) break;
			for (int k = 1; k <= 1000; ++k)
			{
				if (i * j * k > 1000) break;
				vecAns[i * j * k] = min(vecAns[i * j * k], (i * j + j * k + k * i) * 2);
			}
		}
	}

	int iT;
	cin >> iT;

	while (iT--)
	{
		int iN;
		cin >> iN;
		cout << vecAns[iN] << "\n";
	}
	return 0;
}
