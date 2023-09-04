#include <iostream>
#include <vector>
#include <algorithm>

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
	    vector<double> vecHeight(iN,0);
	    for(int i=0;i<iN;++i) cin >> vecHeight[i];
	    for(int i=1;i<iN-1;++i)
	    {
	        if((vecHeight[i-1]+vecHeight[i+1])/2.0 < vecHeight[i])
	        {
	            vecHeight[i] = (vecHeight[i-1]+vecHeight[i+1])/2.0;
	        }
	    }
	    printf("Case #%d: %.20lf\n",t,vecHeight[iN-2]);
	}
}
