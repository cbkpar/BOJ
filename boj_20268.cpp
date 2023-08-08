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
	    int iM, iN;
	    cin >> iM >> iN;
	    vector<vector<bool>> matVisited(2, vector<bool>(2, false));
	    while(iM--)
	    {
	        int iNum;
	        cin >> iNum;
	        matVisited[0][iNum] = true;
	    }
	    while(iN--)
	    {
	        int iNum;
	        cin >> iNum;
	        matVisited[1][iNum] = true;
	    }
	    
	    int iAns = 0;
	    for(int i=0;i<16;++i)
	    {
	        int iTemp = i;
	        int iIndex = 1;
	        vector<vector<bool>> matTemp(2, vector<bool>(2, false));
	        while(iTemp)
	        {
	            if(iTemp&1)
	            {
    	            int iRow = (iIndex-1)/2;
	                int iCol = (iIndex-1)%2;
	                matTemp[0][iRow] = true;
	                matTemp[1][iCol] = true;
	            }
	            ++iIndex;
	            iTemp /= 2;
	        }
	        bool bPossible = true;
	        for(int j=0;j<4;++j)
	        {
	            if(matVisited[j/2][j%2] != matTemp[j/2][j%2])
	            {
	                bPossible = false;
	            }
	        }
	        if(bPossible) ++iAns;
	    }
	    cout << iAns << "\n";
	}
	return 0;
}
