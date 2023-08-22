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
	
	vector<string> vecGene(2,"");
	for(int i=0;i<2;++i) cin >> vecGene[i];
	
	int iLen = vecGene[0].length();
	for(int i=0;i<iLen;++i)
	{
	    if(vecGene[0][i] > vecGene[1][i])
	    {
	        cout << vecGene[0][i];
	    }
	    else
	    {
	        cout << vecGene[1][i];
	    }
	}
	cout << "\n";
	return 0;
}
