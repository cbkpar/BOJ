#include <iostream>
#include <vector>
#include <algorithm>

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
		int iAns = 0;
		int iN;
		cin >> iN;
		for (int i = 0;i < iN;++i)
		{
			int iNum;
			cin >> iNum;
			iAns ^= iNum;
		}
		cout << "Case #" << t << ": " << iAns << "\n";
	}

	return 0;
}
