#include <iostream>

using namespace std;

int main()
{
	int iN, iM;
	cin >> iN >> iM;
	while (true)
	{
		iM += iN;
		if (iM >= 5)
		{
			cout << "yt\n";
			return 0;
		}
		iN += iM;
		if (iN >= 5)
		{
			cout << "yj\n";
			return 0;
		}
	}
	return 0;
}
