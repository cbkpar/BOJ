#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

    if(iN >= 13)
    {
        cout << (iN+1) << "\n";
    }
    else
    {
        cout << iN << "\n";
    }
	return 0;
}
