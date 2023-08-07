#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> vecCount(10,0);
	for(int i=0;i<5;++i)
	{
	    int iNum;
	    cin >> iNum;
	    ++vecCount[iNum];
	}
	for(int i=0;i<10;++i)
	{
	    if(vecCount[i]%2==1)
	    {
	        cout << i << "\n";
	    }
	}
	return 0;
}
