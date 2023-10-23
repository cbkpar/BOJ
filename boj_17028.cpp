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

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	int iAns = 0;
	for (int i = 1; i <= iN; ++i)
	{
		for (int j = i + 1; j <= iN; ++j)
		{
			if (vecNum[i] > vecNum[j])
			{
				iAns = i;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
