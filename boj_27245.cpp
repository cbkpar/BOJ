#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iW, iL, iH;
	cin >> iW >> iL >> iH;

	if (iW >= iH * 2 && iL >= iH * 2)
	{
		if (iW > iL * 2 || iL > iW * 2)
		{
			cout << "bad\n";
		}
		else
		{
			cout << "good\n";
		}
	}
	else
	{
		cout << "bad\n";
	}
	return 0;
}
