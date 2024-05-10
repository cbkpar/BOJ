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
	vector<int> vecNum(iN + 1, 0);
	for (int i = 1;i <= iN;++i)
	{
		vecNum[i] = i;
	}

	while (iM--)
	{
		int iA, iB;
		cin >> iA >> iB;
		vecNum[iA] = iB;
	}

	for (int i = 1;i <= iN;++i)
	{
		cout << vecNum[i] << "\n";
	}
	return 0;
}
