#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	vector<int> vecScore;
	for (int i = 0; i < iN; ++i)
	{
		int iScore;
		cin >> iScore;
		vecScore.push_back(iScore);
	}
	int iX, iY;
	cin >> iX >> iY;
	int iXCount = iN * iX / 100;
	int iYCount = 0;
	for_each(vecScore.begin(), vecScore.end(), [&iYCount, iY](int iScore) {iYCount += (iScore >= iY ? 1 : 0); });
	cout << iXCount << " " << iYCount << endl;
	return 0;
}
