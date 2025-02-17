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

	vector<int> vecNum(iN, 0);
	for(int i=0;i<iN;++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	for(int i=0;i<iN;++i)
	{
		int iX, iY;
		cin >> iX >> iY;
		if(vecNum[i] == 1)
		{
			if(iY > iX)
			{
				iAns += iY - iX;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
