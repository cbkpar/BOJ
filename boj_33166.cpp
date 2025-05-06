#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iP, iQ;
	cin >> iP >> iQ;

	int iA, iB;
	cin >> iA >> iB;

	int iAns = 0;
	for (int t = 1; t <= iQ; ++t)
	{
		iAns += (t <= iP ? iA : iB);
	}

	cout << iAns << "\n";
	return 0;
}
