#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iChic;
	cin >> iChic;

	int iN = sqrt(iChic);
	if (iN * iN != iChic) ++iN;

	for (int i = 0; i < iN + 2; ++i)
	{
		for (int j = 0; j < iN + 2; ++j)
		{
			bool bBound = false;
			if (i == 0) bBound = true;
			if (i == iN + 1) bBound = true;
			if (j == 0) bBound = true;
			if (j == iN + 1) bBound = true;
			cout << (bBound ? "x" : ".") << (j == iN + 1 ? "\n" : "");
		}
	}


	return 0;
}
