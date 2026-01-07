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

	int iH1, iD1, iT1;
	cin >> iH1 >> iD1 >> iT1;

	int iH2, iD2, iT2;
	cin >> iH2 >> iD2 >> iT2;

	int iA = 0;
	int iB = 0;
	while (true)
	{
		if (iA == 0)
		{
			iH2 -= iD1;
			iA = iT1;
		}
		if (iB == 0)
		{
			iH1 -= iD2;
			iB = iT2;
		}
		if (iH1 <= 0 || iH2 <= 0) break;
		--iA;
		--iB;
	}

	if (iH1 <= 0 && iH2 <= 0)
	{
		cout << "draw" << "\n";
	}
	else if (iH1 <= 0)
	{
		cout << "player two" << "\n";
	}
	else
	{
		cout << "player one" << "\n";
	}

	return 0;
}
