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

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	for (int i = 1;i < iN;++i)
	{
		if (vecNum[0] >= vecNum[i])
		{
			cout << i << "\n";
			return 0;
		}
	}

	cout << "infinity" << "\n";

	return 0;
}
