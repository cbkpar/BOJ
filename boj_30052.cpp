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

	int iN, iM;
	cin >> iN >> iM;

	int iD;
	cin >> iD;

	int iAns = 0;
	for(int i=0;i<iN;++i)
	{
		for(int j=0;j<iM;++j)
		{
			int iMax = 0;
			iMax = max(iMax, i+j);
			iMax = max(iMax, i+iM-j-1);
			iMax = max(iMax, iN-i+j-1);
			iMax = max(iMax, iN-i+iM-j-2);
			if(iMax < iD)
			{
				++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
