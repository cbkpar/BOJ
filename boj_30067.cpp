#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vecNum(10, 0);
	for (int i = 0; i < 10; ++i) cin >> vecNum[i];

	int iSum = 0;
	for (int i = 0; i < 10; ++i) iSum += vecNum[i];

	for (int i = 0; i < 10; ++i)
	{
		if (vecNum[i] * 2 == iSum)
		{
			cout << vecNum[i] << "\n";
			return 0;
		}
	}
	return 0;
}
