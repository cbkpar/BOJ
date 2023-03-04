#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	sort(vecNum.begin(), vecNum.end());

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		if (vecNum[i] >= iN - i)
		{
			cout << (iN - i) << "\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}
