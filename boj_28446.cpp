#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	map<int, int> mapNum;

	while (iN-- > 0)
	{
		int iCmd;
		cin >> iCmd;

		if (iCmd == 1)
		{
			int iX, iW;
			cin >> iX >> iW;
			mapNum[iW] = iX;
		}
		else if(iCmd == 2)
		{
			int iW;
			cin >> iW;
			cout << mapNum[iW] << "\n";
		}
	}

	return 0;
}
