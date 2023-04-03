#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(2);
	cin >> vecNum[0] >> vecNum[1];

	sort(vecNum.begin(), vecNum.end());
	++vecNum[1];
	for (int i = vecNum[0] + 1; i <= vecNum[1]; ++i)
	{
		cout << i << "\n";
	}

	return 0;
}
