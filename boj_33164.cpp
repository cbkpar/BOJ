#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	vector<long long> vecA(iN, 0);
	for (int i = 0; i < iN; ++i)
	{
		cin >> vecA[i];
	}
	vector<long long> vecB(iM, 0);
	for (int i = 0; i < iM; ++i)
	{
		cin >> vecB[i];
	}

	long long lAns = 0;
	for (int i = 0; i < iN; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			lAns += (vecA[i] + vecB[j]) * max(vecA[i], vecB[j]);
		}
	}
	
	cout << lAns << "\n";
	return 0;
}
