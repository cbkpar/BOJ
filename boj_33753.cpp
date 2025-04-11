#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	int iT;
	cin >> iT;

	iT -= 30;
	if(iT < 0) iT = 0;

	int iAns = iA + ((iT+iB-1)/iB) * iC;
	cout << iAns << "\n";
	return 0;
}
