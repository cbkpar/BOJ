#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int arrChoose[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> arrChoose[i];
	}

	auto CheckWinner = [&arrChoose](int iIndex)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (i == iIndex)
			{
				continue;
			}
			if (arrChoose[i] == arrChoose[iIndex])
			{
				return false;
			}
		}
		return true;
	};

	for (int i = 0; i < 3; ++i)
	{
		if (CheckWinner(i))
		{
			cout << static_cast<char>(65 + i) << endl;
			return 0;
		}
	}
	cout << "*" << endl;
	return 0;
}
