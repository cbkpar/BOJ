#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	int iN;
	cin >> iN;
	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		iSum += iNum;
	}


	if (iSum >= iT)
	{
		cout << "Padaeng_i Happy" << "\n";
	}
	else
	{
		cout << "Padaeng_i Cry" << "\n";
	}
	return 0;
}
