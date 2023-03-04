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


	for (int i = iN - 2; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			vecNum[j] = abs(vecNum[j] - vecNum[j + 1]);
		}
	}
	cout << vecNum[0] << "\n";
	return 0;
}
