#include <iostream>
#include <string>

using namespace std;

int main()
{
	int iT;
	cin >> iT;
	while (iT--)
	{
		string strA, strB;
		cin >> strA >> strB;
		if (strA == strB)
		{
			cout << "OK" << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}
	return 0;
}
