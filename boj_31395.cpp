#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lAns = 0;

	int iN;
	cin >> iN;
	
	long long lCount = 0;
	int iMax = -1;

	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		if (iNum > iMax)
		{
			++lCount;
		}
		else
		{
			lCount = 1;
		}
		iMax = iNum;
		lAns += lCount;
	}
	cout << lAns << "\n";
	return 0;
}
