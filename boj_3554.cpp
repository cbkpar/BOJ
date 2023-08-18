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

	for (int i = 1; i <= iN; ++i) cin >> vecNum[i];

	int iM;
	cin >> iM;
	while (iM--)
	{
		int iCommand, iL, iR;
		cin >> iCommand >> iL >> iR;

		if (iCommand == 1)
		{
			for (int i = iL; i <= iR; ++i)
			{
				vecNum[i] = (vecNum[i] * vecNum[i]) % 2010;
			}
		}
		else
		{
			int iSum = 0;
			for (int i = iL; i <= iR; ++i)
			{
				iSum += vecNum[i];
			}
			cout << iSum << "\n";
		}
	}
	return 0;
}
