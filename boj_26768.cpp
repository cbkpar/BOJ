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

	for (char ch : str)
	{
		switch (ch)
		{
		case 'a': cout << "4"; break;
		case 'e': cout << "3"; break;
		case 'i': cout << "1"; break;
		case 'o': cout << "0"; break;
		case 's': cout << "5"; break;
		default: cout << ch; break;
		}
	}
	cout << "\n";
	return 0;
}
