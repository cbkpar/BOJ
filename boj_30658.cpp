#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		int iN;
		cin >> iN;
		if (iN == 0) break;

		vector<int> vecNum(iN, 0);
		for (int i = 0; i < iN; ++i) cin >> vecNum[i];
		for (int i = iN - 1; i >= 0; --i) cout << vecNum[i] << "\n";
		cout << "0" << "\n";
	}
	return 0;
}
