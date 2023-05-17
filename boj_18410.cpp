#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecNum(iN + iM, 0);
	for (int i = 0; i < iN + iM; ++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());
	for (int iNum : vecNum)
	{
		cout << iNum << "\n";
	}
	return 0;
}
