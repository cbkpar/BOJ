#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(3, 0);
	for (int i = 0; i < 3; ++i) cin >> vecNum[i];

	sort(vecNum.begin(), vecNum.end());
	cout << vecNum[1] << "\n";

	return 0;
}
