#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lNow = 0;
	long long lSum = 0;

	int iN;
	cin >> iN;
	for (int i = 0;i < iN;++i)
	{
		int iNum;
		cin >> iNum;
		if (iNum == 0)
		{
			--lNow;
		}
		else
		{
			++lNow;
		}
		lSum += lNow;
	}

	cout << lSum << "\n";
	return 0;
}
