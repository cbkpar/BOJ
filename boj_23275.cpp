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

	vector<int> vecCount(1001, 0);
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		++vecCount[iNum];
	}

	for (int i = 0; i < iN-1; ++i)
	{
		int iNum;
		cin >> iNum;
		--vecCount[iNum];
	}

	for (int i = 1; i <= 1000; ++i)
	{
		if (vecCount[i] == 1)
		{
			cout << i << "\n";
		}
	}

	return 0;
}
