#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN;
	cin >> iN;

	int iRight = iN;
	int iLeft = 1;
	bool bRight = true;

	vector<int> vecAns(iN, 0);
	for (int i = iN - 1;i >= 0;--i)
	{
		vecAns[i] = (bRight ? iRight-- : iLeft++);
		bRight = !bRight;
	}

	for (int i = 0;i < iN;++i)
	{
		cout << vecAns[i] << (i == iN - 1 ? "\n" : " ");
	}
	return 0;
}
