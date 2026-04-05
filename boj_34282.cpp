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

	int iSum = iA + iB + iC * 2;

	if (iSum >= 360)
	{
		cout << "A" << "\n";
	}
	else if (iSum >= 320)
	{
		cout << "B" << "\n";
	}
	else if (iSum >= 280)
	{
		cout << "C" << "\n";
	}
	else if (iSum >= 240)
	{
		cout << "D" << "\n";
	}
	else
	{
		cout << "F" << "\n";
	}

	return 0;
}
