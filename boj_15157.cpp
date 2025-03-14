#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int iN;
	cin >> iN;

	int iNow = 1000000000;

	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;

		iNow = min(iNow + 1, iNum);
		cout << iNow << (i == iN - 1 ? "\n" : " ");
	}

	return 0;
}
