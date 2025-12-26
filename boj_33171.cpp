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

	int iA, iB;
	cin >> iA >> iB;

	int iAns = 0;
	for (int i = 1;i <= iN;++i)
	{
		if (i % iA == 0 && i % iB != 0) ++iAns;
		if (i % iA != 0 && i % iB == 0) ++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
