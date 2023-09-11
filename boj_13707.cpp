#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;
	vector<int> vecCount(iN + 1, 1);
	while (--iK)
	{
		vector<int> vecTemp(iN + 1, 0);
		vecTemp[0] = 1;
		for (int i = 1; i <= iN; ++i)
		{
			vecTemp[i] = (vecTemp[i - 1] + vecCount[i])%1000000000;
		}
		for (int i = 0; i <= iN; ++i)
		{
			vecCount[i] = vecTemp[i];
		}
	}
	cout << vecCount[iN] << "\n";
	return 0;
}
