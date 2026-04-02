#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iK;
	cin >> iK;

	int iN;
	cin >> iN;

	int iSum = 0;
	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
		iSum += vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());

	if (iSum - vecNum[0] >= iK)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}

	return 0;
}
