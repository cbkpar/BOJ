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
	
	int iT;
	cin >> iT;
	while(iT--)
	{
	    int iNum;
	    cin >> iNum;

	    int iSum = 0;
	    int iSqrt = (int)sqrt(iNum);
	    
	    for(int i=1;i<=iSqrt;++i)
	    {
	        if(iNum%i==0&&i!=iNum)
	        {
	            iSum += i;
	            if(iNum/i != i && iNum/i != iNum)
	            {
	                iSum += iNum/i;
	            }
	        }
	    }
	    if(iSum > iNum)
	    {
	        cout << "abundant\n";
	    }
	    else if(iSum == iNum)
	    {
	        cout << "perfect\n";
	    }
	    else
	    {
	        cout << "deficient\n";
	    }
	}
	return 0;
}
