#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iW;

	vector<long long> vecThree;
	vector<long long> vecFive;

	cin >> iN >> iW;

	for (int i = 0; i < iN; ++i)
	{
		int iGrade;
		long long lSweet;
		cin >> iGrade >> lSweet;
		if (iGrade == 3)
		{
			vecThree.push_back(lSweet);
		}
		else
		{
			vecFive.push_back(lSweet);
		}
	}
	sort(vecThree.begin(), vecThree.end(), greater<>());
	sort(vecFive.begin(), vecFive.end(), greater<>());

	long long lMax = 0;
	int iSizeThree = vecThree.size();
	int iSizeFive = vecFive.size();
	vector<long long> dpThree(iSizeThree + 1, 0);
	vector<long long> dpFive(iSizeFive + 1, 0);
	for (int i = 1; i <= iSizeThree; ++i) dpThree[i] += dpThree[i - 1] + vecThree[i - 1];
	for (int i = 1; i <= iSizeFive; ++i) dpFive[i] += dpFive[i - 1] + vecFive[i - 1];

	for (int i = 0; i <= iW / 3; ++i)
	{
		int iThree = min(i, iSizeThree);
		int iFive = min((iW - i * 3) / 5, iSizeFive);
		long long lSweet = dpThree[iThree] + dpFive[iFive];
		lMax = max(lMax, lSweet);
	}
	cout << lMax << "\n";
	return 0;
}
