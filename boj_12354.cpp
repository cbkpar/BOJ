#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1; t <= iT; ++t)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum;
		vecNum.push_back(-1);
		for (int i = 0; i < iN; ++i)
		{
			int iNum;
			cin >> iNum;

			int iSize = vecNum.size();
			if (iNum > vecNum[iSize - 1])
			{
				vecNum.push_back(iNum);
			}
			else
			{
				for (int j = 0; j < iSize; ++j)
				{
					if (iNum <= vecNum[j])
					{
						vecNum[j] = iNum;
						break;
					}
				}
			}
		}

		int iAns = iN - vecNum.size() + 1;
		cout << "Case #" << t << ": " << iAns << "\n";
	}
	return 0;
}
