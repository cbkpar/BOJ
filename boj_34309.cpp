#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	vector<string> vecPos(iN, "");
	for (int i = 0;i < iN;++i)
	{
		cin >> vecPos[i];
	}

	int iAns = 0;
	for (int i = 1;i < iN;++i)
	{
		int iR = abs(vecPos[i - 1][0] - vecPos[i][0]);
		int iC = abs(vecPos[i - 1][1] - vecPos[i][1]);
		iAns += iR + iC;
	}
	cout << iAns << "\n";
	return 0;
}
