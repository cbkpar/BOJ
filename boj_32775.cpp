#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;
    
    if(iN <= iM)
    {
        cout << "high speed rail" << "\n";
    }
    else
    {
        cout << "flight" << "\n";
    }

	return 0;
}
