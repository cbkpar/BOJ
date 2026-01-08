#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iK, iB;
	cin >> iN >> iK >> iB;


	vector<int > vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}

	int iAns = 0;
	for (int i = 0;i < iK;++i)
	{
		iAns += vecNum[(iB + i - 1) % iN];
	}

	cout << iAns << "\n";
	return 0;
}
