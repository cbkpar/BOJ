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
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());
	int iSum = 0;
	for (int i = (iN + 1) / 2; i < iN; ++i)
	{
		iSum += vecNum[i];
	}
	cout << iSum << "\n";
	return 0;
}
