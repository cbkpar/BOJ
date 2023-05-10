#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecAns(46, 0);
	vecAns[0] = vecAns[1] = 1;
	for (int i = 2; i <= 45; ++i)
	{
		vecAns[i] = vecAns[i - 1] + vecAns[i - 2];
	}

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		cout << vecAns[iN] << "\n";
	}
	return 0;
}
