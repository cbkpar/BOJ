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

	vector<long long> vecNum(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	long long lK;
	cin >> lK;

	bool bMeet = false;
	for (long long i = 1;i <= iN;++i)
	{
		if (lK * i == vecNum[i]) bMeet = true;
		if (lK * i > vecNum[i] && lK * (i - 1) < vecNum[i - 1]) bMeet = true;
		if (lK * i < vecNum[i] && lK * (i - 1) > vecNum[i - 1]) bMeet = true;
	}

	cout << (bMeet ? "T" : "F") << "\n";
	return 0;
}
