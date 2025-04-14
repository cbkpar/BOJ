#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iL, iH;
	cin >> iL >> iH;

	if(iL%2 == 1)
	{
		int iAns = iH;
		cout << iAns << "\n";
	}
	else
	{
		int iAns = (iH/2)*2;
		cout << iAns << "\n";
	}

	return 0;
}
