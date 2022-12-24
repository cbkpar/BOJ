#include <iostream>

using namespace std;

bool CheckMakePretty(long long lVolume)
{
	if (lVolume % 9 == 0)
	{
		return true;
	}
	if (lVolume % 3 == 2)
	{
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		long long lVolume;
		cin >> lVolume;
		cout << (CheckMakePretty(lVolume) ? "TAK" : "NIE") << "\n";
	}

	return 0;
}
