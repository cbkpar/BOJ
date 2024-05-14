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
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	int iSum = 0;
	int iM;
	cin >> iM;
	while (iM--)
	{
		int iNum;
		cin >> iNum;
		iSum += vecNum[iNum];
	}

	cout << iSum << "\n";
	return 0;
}
