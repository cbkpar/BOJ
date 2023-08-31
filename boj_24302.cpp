#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CalcCost(int iDist)
{
    int iCost1 = 0;
    int iCost2 = 0;
    
    if(iDist <= 5) iCost1 = 400;
    if(iDist > 5 && iDist <= 10) iCost1 = 700;
    if(iDist > 10 && iDist <= 20) iCost1 = 1200;
    if(iDist > 20 && iDist <= 30) iCost1 = 1700;
    if(iDist > 30) iCost1 = 57 * iDist;
    
    if(iDist <= 2) iCost2 = 90 + 90 * iDist;
    if(iDist > 2 && iDist <= 5) iCost2 = 100 + 85 * iDist;
    if(iDist > 5 && iDist <= 20) iCost2 = 125 + 80 * iDist;
    if(iDist > 20 && iDist <= 40) iCost2 = 325 + 70 * iDist;
    if(iDist > 40) iCost2 = 925 + 55 * iDist;
    
    return min(iCost1, iCost2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT = 2;
	int iAns = 0;
	while (iT--)
	{
	    int iDist;
	    cin >> iDist;
	    iAns += CalcCost(iDist/1000);
	}
	printf("%d.%02d\n",iAns/100,iAns%100);
	return 0;
}
