#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iN, iW, iE;
		cin >> iN >> iW >> iE;
		int iSum = 0;
		for (int i = 0;i < iN;++i)
		{
			int iWW, iWE, iEW, iEE;
			cin >> iWW >> iWE >> iEW >> iEE;
			iSum += max(iWW * iW + iEW * iE, iWE * iW + iEE * iE);
		}
		if (t > 1) cout << "\n";
		cout << "Data Set " << t << ":\n";
		cout << iSum << "\n";
	}
	return 0;
}
