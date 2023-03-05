#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	vector<int> vecLength(iN);
	for (int i = 0; i < iN; ++i) cin >> vecLength[i];
	int iMax = -1;
	sort(vecLength.begin(), vecLength.end());
	for (int i = 2; i < iN; ++i)
	{
		if (vecLength[i] < vecLength[i - 1] + vecLength[i - 2])
		{
			iMax = vecLength[i] + vecLength[i - 1] + vecLength[i - 2];
		}
	}
	cout << iMax << "\n";
	return 0;
}
