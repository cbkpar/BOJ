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

	vector<int> vecA(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecA[i];

	vector<int> vecB(iN, 0);
	for (int i = 0; i < iN; ++i) cin >> vecB[i];

	int iCountA = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iN; ++j)
		{
			if (vecA[i] > vecB[j]) ++iCountA;
			if (vecA[i] < vecB[j]) --iCountA;
		}
	}

	if (iCountA > 0)
	{
		cout << "first" << "\n";
	}
	else if (iCountA == 0)
	{
		cout << "tie" << "\n";
	}
	else
	{
		cout << "second" << "\n";
	}
	return 0;
}
