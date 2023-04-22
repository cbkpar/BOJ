#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	vector<int> vecS(iN + 1, 0);
	vector<int> vecD(iN + 1, 0);

	for (int i = 1; i <= iN; ++i) cin >> vecS[i];
	for (int i = 1; i <= iN; ++i) cin >> vecD[i];

	vector<int> vecOrigin(iN + 1, 0);
	for (int i = 1; i <= iN; ++i) vecOrigin[i] = i;
	while (iK--)
	{
		vector<int> vecTemp(iN + 1, 0);
		for (int i = 1; i <= iN; ++i)
		{
			vecTemp[i] = vecOrigin[vecD[i]];
		}
		for (int i = 1; i <= iN; ++i)
		{
			vecOrigin[i] = vecTemp[i];
		}
	}
	vector<int> vecAns(iN + 1, 0);
	for (int i = 1; i <= iN; ++i)
	{
		vecAns[vecOrigin[i]] = vecS[i];
	}
	for (int i = 1; i <= iN; ++i)
	{
		cout << vecAns[i] << (i == iN ? "\n" : " ");
	}
	return 0;
}
