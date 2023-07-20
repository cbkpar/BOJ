#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iN, iM;
	cin >> iN >> iM;
	
	vector<vector<int>> vecNode(iN+1,vector<int>());
	while(iM--)
	{
	    int iA, iB;
	    cin >> iA >> iB;
	    if(iA > iB)
	    {
	        swap(iA, iB);
	    }
	    vecNode[iA].push_back(iB);
	}
	
	vector<double> vecAmount(iN+1,0.0);
	vecAmount[1] = 100.0;
	
	for(int i=1;i<=iN;++i)
	{
	    int iSize = vecNode[i].size();
	    if(iSize > 0)
	    {
	        for(int iNext : vecNode[i])
	        {
	            vecAmount[iNext] += vecAmount[i] / (double)(iSize);
	        }
	        vecAmount[i] = 0;
	    }
	}
	
	double dMax = 0.0;
	for(int i=1;i<=iN;++i)
	{
	    dMax = max(dMax, vecAmount[i]);
	}
	
	cout << fixed;
	cout.precision(30);
	cout << dMax << "\n";
	return 0;
}
