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
	vector<int> vecCount(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecCount[i];
	}

	int iK;
	cin >> iK;
	for (int i = 0;i<iK;++i)
	{
		int iNum;
		cin >> iNum;
		--vecCount[iNum];
	}

	for (int i = 1;i <= iN;++i)
	{
		if (vecCount[i] >= 0)
		{
			cout << "no" << "\n";
		}
		else
		{
			cout << "yes" << "\n";
		}
	}

	return 0;
}
