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

	vector<int> vecNumber;

	for (int i = 0; i < iN * 3; ++i)
	{
		int iNumber;
		cin >> iNumber;
		vecNumber.push_back(iNumber);
	}
	sort(vecNumber.begin(), vecNumber.end());
	cout << (vecNumber[iN * 2 - 1] - vecNumber[iN]) << "\n";

	return 0;
}
