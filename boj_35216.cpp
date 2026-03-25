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

	int iS;
	cin >> iS;

	for (int i = -999;i <= 999;++i)
	{
		if (i == 0) continue;
		for (int j = -999;j <= 999;++j)
		{
			if (j == 0) continue;
			if (i + j == iS)
			{
				cout << i << " " << j << "\n";
				return 0;
			}
		}
	}

	return 0;
}
