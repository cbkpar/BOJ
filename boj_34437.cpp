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


	int iAns = 0;
	int iN;
	cin >> iN;
	while (true)
	{
		if (iN == 1) break;
		if (iN % 2 == 0)
		{
			iN /= 2;
		}
		else
		{
			iN += iN * 2 + 1;
		}
		++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
