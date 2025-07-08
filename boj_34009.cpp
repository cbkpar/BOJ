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
	vector<long long> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}
	sort(vecNum.begin(), vecNum.end());

	bool bAlice = true;
	if (iN % 2 == 1)
	{
		bAlice = false;
	}

	if (bAlice)
	{
		cout << "Alice" << "\n";
	}
	else
	{
		cout << "Bob" << "\n";
	}
	return 0;
}
