#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iAns = 0;

	vector<int> vecCount(5, 0);
	for (int i = 0; i < 10; ++i)
	{
		int iN;
		cin >> iN;
		vecCount[iN]++;
	}
	
	for (int i = 1; i <= 4; ++i)
	{
		if (vecCount[i] == 0)
		{
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;

}
