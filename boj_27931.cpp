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
	
	int iN;
	cin >> iN;
	
	vector<long long> vecOdd;
	vector<long long> vecEven;
	
	for(int i=0;i<iN;++i)
	{
	    long long lNum;
	    cin >> lNum;
	    if(lNum%2==0)
	    {
	        vecEven.push_back(lNum);
	    }
	    else
	    {
	        vecOdd.push_back(lNum);
	    }
	}

	vector<long long> vecAns(2,2000000001);
	sort(vecEven.begin(), vecEven.end());
	sort(vecOdd.begin(), vecOdd.end());
	
	int iSizeEven = vecEven.size();
	int iSizeOdd = vecOdd.size();
	
	for(int i=0;i<iSizeEven-1;++i)
	{
        vecAns[0] = min(vecAns[0], vecEven[i+1]-vecEven[i]);
	}
	for(int i=0;i<iSizeOdd-1;++i)
	{
        vecAns[0] = min(vecAns[0], vecOdd[i+1]-vecOdd[i]);
	}
	
	int iEvenIndex = 0;
	int iOddIndex = 0;
	while(iEvenIndex < iSizeEven && iOddIndex < iSizeOdd)
	{
	    long long lDiff = abs(vecEven[iEvenIndex]-vecOdd[iOddIndex]);
        vecAns[1] = min(vecAns[1], lDiff);
        if(vecEven[iEvenIndex] < vecOdd[iOddIndex])
        {
            ++iEvenIndex;
        }
        else
        {
            ++iOddIndex;
        }
	}
	
	for(int i=0;i<2;++i) if(vecAns[i] == 2000000001) vecAns[i] = -1;
    cout << vecAns[0] << " " << vecAns[1] << "\n";
	return 0;
}
