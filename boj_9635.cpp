#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	while(iT--)
	{
		int iN,iX,iY;
		cin >> iN >> iX >> iY;

		vector<int> vecNum(iN,0);
		for(int i=0;i<iN;++i) cin >> vecNum[i];

		bool bFirst = false;
		bool bSecond = false;
		if(iX==vecNum[0]) bFirst = true;
		if(iY==vecNum[iN-1]) bSecond = true;

		if(bFirst&&bSecond) cout << "BOTH" << "\n";
		if(bFirst&&!bSecond) cout << "EASY" << "\n";
		if(!bFirst&&bSecond) cout << "HARD" << "\n";
		if(!bFirst&&!bSecond) cout << "OKAY" << "\n";
	}
	return 0;
}
