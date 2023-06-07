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
	while (cin >> iN)
	{
		int iSum = 1;
		int iIndex = 1;
		while (true)
		{
			if (iSum >= iN) break;
			++iIndex;
			iSum += iIndex;
		}
		int iA = iSum - iN + 1;
		int iB = (iIndex + 1) - iA;
		if (iIndex % 2 == 0) swap(iA, iB);
		cout << "TERM " << iN << " IS " << iA << "/" << iB << "\n";
	}
	return 0;
}
