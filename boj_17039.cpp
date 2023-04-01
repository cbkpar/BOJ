#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(3);
	for (int i = 0; i < 3; ++i) cin >> vecNum[i];

	sort(vecNum.begin(), vecNum.end());

	int iA, iB;
	iA = vecNum[1] - vecNum[0];
	iB = vecNum[2] - vecNum[1];

	if (iA == 1 && iB == 1)
	{
		cout << "0\n";
	}
	else if (iA == 2 || iB == 2)
	{
		cout << "1\n";
	}
	else
	{
		cout << "2\n";
	}
	cout << (max(iA, iB) - 1) << "\n";
	return 0;
}
