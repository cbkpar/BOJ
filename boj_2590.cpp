#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecCount(6);
	for (int i = 0; i < 6; ++i) cin >> vecCount[i];

	int iAns = 0;
	iAns += vecCount[3] + vecCount[4] + vecCount[5];
	vecCount[0] -= vecCount[4] * 11;
	vecCount[1] -= vecCount[3] * 5;

	iAns += vecCount[2] / 4;

	switch (vecCount[2] % 4)
	{
	case 0:
		break;
	case 1:
		++iAns;
		vecCount[1] -= 5;
		vecCount[0] -= 7;
		break;
	case 2:
		++iAns;
		vecCount[1] -= 3;
		vecCount[0] -= 6;
		break;
	case 3:
		++iAns;
		vecCount[1] -= 1;
		vecCount[0] -= 5;
		break;
	}
	if (vecCount[1] < 0)
	{
		vecCount[0] += vecCount[1] * 4;
		vecCount[1] = 0;
	}
	if (vecCount[0] < 0)
	{
		vecCount[0] = 0;
	}
	iAns += (vecCount[1] * 4 + vecCount[0] + 35) / 36;

	cout << iAns << "\n";
	return 0;
}
