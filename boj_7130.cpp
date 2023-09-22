#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iM, iH;
	cin >> iM >> iH;

	int iN;
	cin >> iN;

	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iC, iB;
		cin >> iC >> iB;

		iSum += max(iC * iM, iB * iH);
	}

	cout << iSum << "\n";
	return 0;
}
