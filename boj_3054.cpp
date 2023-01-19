#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int iLen = str.length();

	cout << ".";
	for (int i = 1;i <= iLen;++i)
	{
		cout << "." << (i % 3 == 0 ? "*" : "#") << "..";
	}
	cout << "\n";

	cout << ".";
	for (int i = 1;i <= iLen;++i)
	{
		cout << (i % 3 == 0 ? "*" : "#") << "." << (i % 3 == 0 ? "*" : "#") << ".";
	}
	cout << "\n";

	for (int i = 1;i <= iLen;++i)
	{
		cout << ((i % 3 == 0 || (i % 3 == 1 && i > 1)) ? "*" : "#") << "." << str[i - 1] << ".";
	}
	cout << (iLen % 3 == 0 ? "*" : "#") << "\n";

	cout << ".";
	for (int i = 1;i <= iLen;++i)
	{
		cout << (i % 3 == 0 ? "*" : "#") << "." << (i % 3 == 0 ? "*" : "#") << ".";
	}
	cout << "\n";

	cout << ".";
	for (int i = 1;i <= iLen;++i)
	{
		cout << "." << (i % 3 == 0 ? "*" : "#") << "..";
	}
	cout << "\n";

	return 0;
}
