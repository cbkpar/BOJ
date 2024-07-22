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
		int iN;
		cin >> iN;
		if (iN == 0) break;

		int iAns = 0;

		int iA = 0;
		int iB = 0;
		int iC = 0;

		for (int i = 0;i < iN;++i)
		{
			iA = iB;
			iB = iC;
			cin >> iC;
			iAns = max(iAns, iA + iB + iC);
		}
		cout << iAns << "\n";
	}
	return 0;
}
