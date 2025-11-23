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

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		string strCommand;
		cin >> strCommand;

		int iCount;
		cin >> iCount;

		if (strCommand == "+")
		{
			iN += iCount;		
		}
		else
		{
			iN -= iCount;
		}
	}

	cout << iN << "\n";
	return 0;
}
