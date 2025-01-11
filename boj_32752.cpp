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

	int iN, iL, iR;
	cin >> iN >> iL >> iR;

	vector<int> vecNum(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecNum[i];
	}

	sort(vecNum.begin() + iL - 1, vecNum.begin() + iR);

	bool bPossible = true;
	for (int i = 1; i < iN; ++i)
	{
		if (vecNum[i] < vecNum[i - 1])
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "1" : "0") << "\n";
	return 0;
}
