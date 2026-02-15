#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iN;
		cin >> iN;

		set<int> setNum;
		for (int i = 0;i < iN;++i)
		{
			int iNum;
			cin >> iNum;
			setNum.insert(iNum);
		}

		int iAns = setNum.size() * 2 - 1;
		cout << iAns << "\n";
	}

	return 0;
}
