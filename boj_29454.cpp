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

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
		iSum += vecNum[i];
	}

	for (int i = 1; i <= iN; ++i)
	{
		if (vecNum[i] == iSum - vecNum[i])
		{
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}
