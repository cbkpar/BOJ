#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		int iN;
		cin >> iN;
		vector<int> vecNum(iN, 0);
		for (int i = 0;i < iN;++i)
		{
			cin >> vecNum[i];
		}

		int iNow = 0;
		while (true)
		{
			++iNow;
			set<int> setNum;
			for (int i = 0;i < iN;++i)
			{
				setNum.insert(vecNum[i] % iNow);
			}
			if (setNum.size() == iN)
			{
				cout << iNow << "\n";
				break;
			}
		}
	}
	return 0;
}
