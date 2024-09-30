#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iA, iB;
	cin >> iN >> iA >> iB;

	int iLenA = 1;
	int iLenB = 1;

	for (int i = 0;i < iN;++i)
	{
		iLenA += iA;
		iLenB += iB;
		if (iLenB > iLenA) swap(iLenA, iLenB);
		if (iLenA == iLenB) --iLenB;
	}

	cout << iLenA << " " << iLenB << "\n";
	return 0;
}
