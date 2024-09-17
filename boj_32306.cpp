#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecA(3, 0);
	vector<int> vecB(3, 0);
	
	for (int i = 0; i < 3; ++i)
	{
		cin >> vecA[i];
	}
	for (int i = 0; i < 3; ++i)
	{
		cin >> vecB[i];
	}

	int iSumA = vecA[0] + vecA[1] * 2 + vecA[2] * 3;
	int iSumB = vecB[0] + vecB[1] * 2 + vecB[2] * 3;

	int iAns = 0;
	if (iSumA > iSumB) iAns = 1;
	if (iSumA < iSumB) iAns = 2;

	cout << iAns << "\n";
	return 0;
}
