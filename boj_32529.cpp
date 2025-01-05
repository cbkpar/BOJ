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

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		cin >> vecNum[i];
	}

	int iSum = 0;
	for (int i = iN; i > 0; --i)
	{
		iSum += vecNum[i];
		if (iSum >= iM)
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1" << "\n";
	return 0;
}
