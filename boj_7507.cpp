#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iT;
	cin >> iT;
	for(int t=1;t<=iT;++t)
	{
		int iN;
		cin >> iN;
		vector<tuple<int,int,int>> vecNum;
		for(int i=0;i<iN;++i)
		{
			int iD, iS, iE;
			cin >> iD >> iS >> iE;
			vecNum.push_back(make_tuple(iD,iS,iE));
		}
		sort(vecNum.begin(), vecNum.end());
		int iAns = 0;
		int iBefore = -1;
		vector<int> vecCount(2401, 0);
		for(int i=0;i<iN;++i)
		{
			if(get<0>(vecNum[i]) != iBefore)
			{
				iAns += vecCount[2400];
				iBefore = get<0>(vecNum[i]);
				vecCount = vector<int>(2401, 0);
			}

			int iS = get<1>(vecNum[i]);
			int iE = get<2>(vecNum[i]);
			vecCount[iE] = max(vecCount[iS]+1,vecCount[iE]);
			for(int i=iE+1;i<=2400;++i)
			{
				vecCount[i] = max(vecCount[i], vecCount[i-1]);
			}

			if(i==iN-1)
			{
				iAns += vecCount[2400];
				iBefore = get<0>(vecNum[i]);
			}
		}
		if(t != 1) cout << "\n";
		cout << "Scenario #" << t << ":" << "\n";
		cout << iAns << "\n";

	}
	return 0;
}
