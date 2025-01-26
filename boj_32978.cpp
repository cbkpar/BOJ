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

	vector<string> vecA(iN, "");
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecA[i];
	}

	vector<string> vecB(iN - 1, "");
	for (int i = 0; i < iN - 1; ++i)
	{
		cin >> vecB[i];
	}

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());

	for (int i = 0; i < iN - 1; ++i)
	{
		if (vecA[i] != vecB[i])
		{
			cout << vecA[i] << "\n";
			return 0;
		}
	}
	cout << vecA[iN - 1] << "\n";
	return 0;
}
