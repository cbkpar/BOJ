#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	int iAns = 0;
	for (int i = 0;i < iN;++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		if (iA < 0) ++iA;
		if (iB < 0) ++iB;
		iAns += (iB - iA);
	}
	if (iAns >= 0)
	{
		++iAns;
	}
	cout << iAns << "\n";
	return 0;
}
