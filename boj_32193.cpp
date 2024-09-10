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

	int iN;
	cin >> iN;

	int iNow = 0;
	for(int i=0;i<iN;++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		iNow += iA;
		iNow -= iB;
		cout << iNow << "\n";
	}

	return 0;
}
