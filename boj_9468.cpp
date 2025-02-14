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

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vector<int> vecNum(15, 0);
		for (int j = 0; j < 15; ++j)
		{
			cin >> vecNum[j];
		}

		int iSum = 0;
		for (int k = 1; k < 15; ++k)
		{
			if (vecNum[k] == vecNum[k - 1] + 1)
			{
				++iSum;
			}
		}

		cout << i << " " << iSum << "\n";
	}

	return 0;
}
