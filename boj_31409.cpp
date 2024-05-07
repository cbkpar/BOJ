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
	vector<int> vecNum(iN+1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	for (int i = 1;i <= iN;++i)
	{
		if (vecNum[i] == i)
		{
			++iAns;
			if (i == 1)
			{
				vecNum[i] = 2;
			}
			else
			{
				vecNum[i] = 1;
			}
		}
	}

	cout << iAns << "\n";
	for (int i = 1;i <= iN;++i)
	{
		cout << vecNum[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
