#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSum = 0;
	for (int i = 0; i < 5; ++i)
	{
		int iA, iL;
		cin >> iA >> iL;

		iSum += iA * iL;
	}
	iSum /= 5;


	int iN, iKWF;
	cin >> iN >> iKWF;
	int iAns = (iSum * iN) / iKWF;
	cout << iAns << "\n";
	return 0;
}
