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

	int iA, iB, iC;
	cin >> iA >> iB >> iC;

	int iAns = 0;
	
	iAns += iA * 2;

	if (iC >= 2)
	{
		iC -= 2;
		iAns += iB * 2 + 3;
	}

	iAns += (iC / 2) * 3;
	cout << iAns << "\n";
	return 0;
}
