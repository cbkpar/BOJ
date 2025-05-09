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

	int iN, iM;
	cin >> iN >> iM;

	vector<int> vecA(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecA[i];
	}

	vector<int> vecB(iM, 0);
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecB[i];
	}

	int iAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			if (vecA[i] <= vecB[j])
			{
				++iAns;
			}
		}
	}

	cout << iAns << "\n";
	return 0;
}
