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
		string str;
		cin >> str;
		int iLength = str.length();
		cout << str[0];
		for (int i = 1; i < iLength; ++i)
		{
			if (str[i - 1] != str[i])
			{
				cout << str[i];
			}
		}
		cout << "\n";
	}

	return 0;
}
