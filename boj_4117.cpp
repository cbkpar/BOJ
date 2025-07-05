#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN, iA, iB, iC;
		cin >> iN >> iA >> iB >> iC;

		if (iN == 0 && iA == 0 && iB == 0 && iC == 0)
		{
			break;
		}

		int iAns = 0;
		iAns += iN * 3 - 1;
		iAns += iN + (iB - iA + iN) % iN;
		iAns += (iB - iC + iN) % iN;
		cout << iAns << "\n";
	}
	return 0;
}
