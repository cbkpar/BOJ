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

	vector<pair<int, int>> vecNum(3, { 0,0 });
	for (int i = 0; i < 3; ++i)
	{
		cin >> vecNum[i].first >> vecNum[i].second;
	}

	for (int i = 0; i <= vecNum[0].first; ++i)
	{
		int iAB = i;
		int iAC = vecNum[0].first - iAB;
		if (iAC < 0) continue;

		int iBC = vecNum[2].second - iAC;
		if (iBC < 0) continue;

		int iBA = vecNum[1].first - iBC;
		if (iBA < 0) continue;

		int iCA = vecNum[0].second - iBA;
		if (iCA < 0) continue;

		int iCB = vecNum[2].first - iCA;
		if (iCB < 0) continue;

		cout << "1" << "\n";
		cout << iAB << " " << iAC << "\n";
		cout << iBA << " " << iBC << "\n";
		cout << iCA << " " << iCB << "\n";
		return 0;
	}

	cout << "0" << "\n";
	return 0;
}
