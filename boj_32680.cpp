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

	int iMax = 0;
	int iMin = 2000000000;
	for(int i=0;i<iN;++i)
	{
		int iA, iB;
		cin >> iA >> iB;
		iMax = max(iMax, iA);
		iMin = min(iMin, iB);
	}

	if(iMax <= iMin)
	{
		cout << (iMin-iMax+1) << " " << iMax << "\n";
	}
	else
	{
		cout << "bad news" << "\n";
	}

	return 0;
}
