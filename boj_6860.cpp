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
	
	vector<string> vecGene(2, "");
	for(int i=0;i<2;++i) cin >> vecGene[i];
	
	vector<vector<bool>> matPossible(5, vector<bool>(2, false));
	
	for(int i=0;i<5;++i)
	{
	    for(int j=0;j<2;++j)
	    {
	        if(vecGene[0][i*2+j]=='A'+i) matPossible[i][0] = true;
	        if(vecGene[1][i*2+j]=='A'+i) matPossible[i][0] = true;
	    }
	    if(vecGene[0][i*2]=='a'+i && vecGene[1][i*2]=='a'+i) matPossible[i][1] = true;
	    if(vecGene[0][i*2+1]=='a'+i && vecGene[1][i*2]=='a'+i) matPossible[i][1] = true;
	    if(vecGene[0][i*2]=='a'+i && vecGene[1][i*2+1]=='a'+i) matPossible[i][1] = true;
	    if(vecGene[0][i*2+1]=='a'+i && vecGene[1][i*2+1]=='a'+i) matPossible[i][1] = true;
	}
	
	int iN;
	cin >> iN;
	while(iN--)
	{
	    string strGene;
	    cin >> strGene;
	    
	    bool bPossible = true;
	    for(int i=0;i<5;++i)
	    {
	        if(strGene[i] >= 'A' && strGene[i] <= 'Z')
	        {
	            if(!matPossible[i][0]) bPossible = false;
	        }
	        else
	        {
	            if(!matPossible[i][1]) bPossible = false;
	        }
	    }
	    
	    if(bPossible)
	    {
	        cout << "Possible baby.\n";
	    }
	    else
	    {
	        cout << "Not their baby!\n";
	    }
	}
	return 0;
}
