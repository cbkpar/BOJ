#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	while (iN--)
	{
		int iR, iC;
		cin >> iR >> iC;
		for (int i = 0; i < iR; ++i)
		{
			string str;
			cin >> str;
			for (int j = iC - 1; j >= 0; --j)
			{
				cout << str[j];
			}
			cout << "\n";
		}
	}
	return 0;
}
