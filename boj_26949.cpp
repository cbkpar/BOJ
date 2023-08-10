#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iPa, iKa, iPb, iKb, iN;
	cin >> iPa >> iKa >> iPb >> iKb >> iN;

	vector<int> vecAns(2, 0);
	int iAns = 1000000000;

	int iMax = iN / iKa;
	for (int i = 0; i <= iMax; ++i)
	{
		int iRest = iN - iKa * i;
		int iTotal = i * iPa + (iRest + iKb - 1) / iKb * iPb;
		if (iAns > iTotal)
		{
			iAns = iTotal;
			vecAns[0] = i;
			vecAns[1] = (iRest + iKb - 1) / iKb;
		}
	}
	cout << vecAns[0] << " " << vecAns[1] << " " << iAns << "\n";
	return 0;
}
