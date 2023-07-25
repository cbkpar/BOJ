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
	while(iT--)
	{
	    int iN;
	    cin >> iN;
	    
	    bool bPossible = true;
	    int iNum;
	    cin >> iNum;
	    
	    int iNow = min(iNum, iN - iNum + 1);
	    
	    for(int i=1;i<iN;++i)
	    {
	        int iTemp;
	        cin >> iTemp;
	        int iA = iTemp;
	        int iB = iN - iTemp + 1;
	        if(iA > iB) swap(iA, iB);
	        
	        if(iA >= iNow)
	        {
	            iNow = iA;
	        }
	        else if(iB >= iNow)
	        {
	            iNow = iB;
	        }
	        else
	        {
	            bPossible = false;
	        }
	    }
	    cout << (bPossible?"YES\n":"NO\n");
	}
	return 0;
}
