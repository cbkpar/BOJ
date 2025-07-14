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

	int iN;
	cin >> iN;

	int iAns = 0;

	map<string, int> mapCount;
	for (int i = 0;i < iN;++i)
	{
		string strResult;
		cin >> strResult;

		mapCount[strResult] += 1;
	}

	for (int i = 0;i < iN;++i)
	{
		string strResult;
		cin >> strResult;

		if (mapCount[strResult] > 0)
		{
			--mapCount[strResult];
			++iAns;
		}
	}

	cout << iAns << "\n";
	return 0;
}
