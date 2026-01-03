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

	bool bIncrease = true;


	vector<long long> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
	}
	for (int i = 1;i < iN;++i)
	{
		if (vecNum[i] <= vecNum[i - 1]) bIncrease = false;
	}

	if (bIncrease)
	{
		cout << "1" << "\n";
	}
	else
	{
		cout << "0" << "\n";
	}

	return 0;
}
