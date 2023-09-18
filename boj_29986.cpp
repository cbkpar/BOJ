#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iH;
	cin >> iN >> iH;

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iCritical;
		cin >> iCritical;

		if (iCritical <= iH)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
