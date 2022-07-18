#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;
	while (iN--)
	{
		string str;
		cin >> str;
		if (str.length() >= 6 && str.length() <= 9)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}
