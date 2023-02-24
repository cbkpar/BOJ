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

	int iSum = 0;
	while (iN--)
	{
		int iH, iB, iK;
		cin >> iH >> iB >> iK;
		if (iB > iH)
		{
			iSum += (iB - iH) * iK;
		}
	}
	cout << iSum << "\n";

	return 0;
}
