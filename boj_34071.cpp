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

	int iMin = 10000;
	int iMax = -1;

	vector<int> vecNum(iN, 0);
	for (int i = 0;i < iN;++i)
	{
		cin >> vecNum[i];
		iMin = min(iMin, vecNum[i]);
		iMax = max(iMax, vecNum[i]);
	}

	if (iMax == vecNum[0])
	{
		cout << "hard" << "\n";
	}
	else if (iMin == vecNum[0])
	{
		cout << "ez" << "\n";
	}
	else
	{
		cout << "?" << "\n";
	}
	

	return 0;
}
