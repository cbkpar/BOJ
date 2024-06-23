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
	for (int i = 0; i < 4; ++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin(), vecNum.end());

	int iAns = vecNum[0] * vecNum[1] + vecNum[2] * vecNum[3];
	cout << iAns << "\n";
	return 0;
}
