#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(4, 0);
	for (int i = 0;i < 4;++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin(), vecNum.end());

	int iSum = 1;
	for (int i = 1;i < 4;++i) iSum += vecNum[i];

	cout << iSum << "\n";
	return 0;
}
