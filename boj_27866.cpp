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

	string strA;
	cin >> strA;
	int iN;
    cin >> iN;
	cout << strA[iN-1] << "\n";
	return 0;
}
