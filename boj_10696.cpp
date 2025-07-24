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

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		string strN;
		cin >> strN;
		int iX;
		cin >> iX;
		int iAns = 0;
		for (char ch : strN)
		{
			iAns *= 10;
			iAns = (iAns + (ch - '0')) % iX;
		}
		
		cout << "Case " << t << ": ";
		cout << iAns << "\n";
	}
	return 0;
}
