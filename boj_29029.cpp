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

	string strDir;
	cin >> strDir;

	vector<int> vecCount(4, 0);
	for (int i = 0; i < iN; ++i)
	{
		if (strDir[i] == 'N') ++vecCount[0];
		if (strDir[i] == 'S') ++vecCount[1];
		if (strDir[i] == 'E') ++vecCount[2];
		if (strDir[i] == 'W') ++vecCount[3];
	}

	int iAns = iN;
	for (int i = 0; i < 4; ++i)
	{
		iAns = min(iAns, iN-vecCount[i]);
	}

	cout << iAns << "\n";
	return 0;
}
