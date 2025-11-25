#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	int iN;
	cin >> iN;

	int iNowA = 1;
	int iNowB = 1;

	while (iN > iC)
	{
		iN -= iC;
		++iNowB;
		if (iNowB > iB)
		{
			++iNowA;
			iNowB = 1;
		}
	}

	cout << iNowA << " " << iNowB << "\n";
	return 0;
}
