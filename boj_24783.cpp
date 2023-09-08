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
	    int iA, iB, iC;
	    cin >> iA >> iB >> iC;
	    if(iA<iB) swap(iA,iB);
	    
	    bool bPossible = false;
	    if(iA+iB==iC) bPossible = true;
	    if(iA-iB==iC) bPossible = true;
	    if(iA*iB==iC) bPossible = true;
	    if(iA%iB==0&&iA/iB==iC) bPossible = true;
	    
	    cout << (bPossible?"Possible":"Impossible") << "\n";
	}
	return 0;
}
