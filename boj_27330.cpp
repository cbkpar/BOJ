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
	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecNum[i];

	vector<bool> vecReset(1001, false);
	int iM;
	cin >> iM;
	for (int i = 0; i < iM; ++i)
	{
		int iNum;
		cin >> iNum;
		vecReset[iNum] = true;
	}

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		iSum += vecNum[i];
		if (vecReset[iSum])
		{
			iSum = 0;
		}
	}

	cout << iSum << "\n";
	return 0;
}
