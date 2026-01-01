#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int iA, iB, iC, iD;
    cin >> iA >> iB >> iC >> iD;
    
    if(iA+iB <= iD && iC <= iD) cout << "~.~" << "\n";
    if(iA+iB > iD && iC <= iD) cout << "Walk" << "\n";
    if(iA+iB <= iD && iC > iD) cout << "Shuttle" << "\n";
    if(iA+iB > iD && iC > iD) cout << "T.T" << "\n";

	return 0;
}
