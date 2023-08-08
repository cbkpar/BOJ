#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int iN;
	cin >> iN;
	while(iN--)
	{
	    string strCode;
	    cin >> strCode;
	    
	    int iOne = 0;
	    int iTwo = 0;
	    
	    for(int i=0;i<13;++i)
	    {
	        iOne += strCode[i] - '0';
	    }
	    for(int i=10;i<13;++i)
	    {
	        iTwo *= 10;
	        iTwo += strCode[i] - '0';
	    }
	    int iTotal = (iTwo * 10 + iOne);
	    if(iTotal < 1000) iTotal += 1000;
	    iTotal %= 10000;
	    
	    printf("%04d\n", iTotal);
	}
	return 0;
}
