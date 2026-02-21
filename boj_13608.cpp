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

	while (true)
	{
		int iT;
		cin >> iT;
		if (iT == 0)
		{
			break;
		}

		int iCount = 0;
		for (int i = 0;i < iT;++i)
		{
			int iC, iV;
			cin >> iC >> iV;
			iCount += iV / 2;
		}
		int iAns = iCount / 2;
		cout << iAns << "\n";
	}

	return 0;
}
