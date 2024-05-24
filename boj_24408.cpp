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

	bool bFirst = true;

	int iM;

	for (int i = 1;i < iN;++i)
	{
		int iNum;
		cin >> iNum;

		if (bFirst)
		{
			iM = iNum;
			bFirst = false;
		}
		else if (iNum % iM == 0)
		{
			cout << iNum << "\n";
			bFirst = true;
		}
	}

	return 0;
}
