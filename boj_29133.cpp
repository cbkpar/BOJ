#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lA, lB, lC, lD;
	cin >> lA >> lB >> lC >> lD;

	vector<int> vecAns;

	if (lA + lB + lC == lD)
	{
		vecAns.push_back(1);
	}
	if (lA * lA + lB * lB + lC * lC == lD)
	{
		vecAns.push_back(2);
	}
	if (lA * lA * lA + lB * lB * lB + lC * lC * lC == lD)
	{
		vecAns.push_back(3);
	}

	if (vecAns.size() != 1)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << vecAns[0] << "\n";
	}
	return 0;
}
