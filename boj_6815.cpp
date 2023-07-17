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

    int iA, iB;
    cin >> iA >> iB;
    
    int iAns = 0 ;
    
    for(int i=1;i<464;++i)
    {
        int iTriple = i*i*i;
        if(iTriple >= iA && iTriple <= iB)
        {
            int iSqrt = (int)sqrt(iTriple);
            if(iSqrt*iSqrt == iTriple)
            {
                ++iAns;
            }
        }
    }

    cout << iAns << "\n";
	return 0;
}
