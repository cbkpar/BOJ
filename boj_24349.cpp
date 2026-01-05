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

	int iN, iA, iB, iC;
	cin >> iN >> iA >> iB >> iC;

	int iAns = 0;
	iN--;
	if (iN > 0)
	{
		iAns += min(iA, iB);
	}
	iN--;
	if (iN > 0)
	{
		iAns += min(iA, min(iB, iC)) * iN;
	}
	cout << (iAns / 100) << " " << (iAns % 100) << "\n";

	return 0;
}
