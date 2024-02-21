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

	vector<int> vecNum(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		cin >> vecNum[i];
	}

	vector<int> vecNext(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		vecNext[vecNum[i]] = i;
	}

	vector<int> vecNow(iN + 1, 0);
	for (int i = 1;i <= iN;++i) cin >> vecNow[i];

	for (int t = 1;t <= 3;++t)
	{
		vector<int> vecTemp(iN + 1, 0);
		for (int i = 1;i <= iN;++i)
		{
			vecTemp[vecNext[i]] = vecNow[i];
		}
		for (int i = 1;i <= iN;++i)
		{
			vecNow[i] = vecTemp[i];
		}
	}

	for (int i = 1;i <= iN;++i)
	{
		cout << vecNow[i] << "\n";
	}
	return 0;
}
