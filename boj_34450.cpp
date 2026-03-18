#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	int iP;
	cin >> iP;

	int iSum = 0;
	for (int i = 0;i < iN - 1;++i)
	{
		int iNum;
		cin >> iNum;
		iSum += iNum;
	}

	int iAns = (iN - 1) * iN / 2 - iSum + iN * iP;
	cout << iAns << "\n";

	return 0;
}
