#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	while (iN--)
	{
		string strName;
		cin >> strName;
		for (char ch : strName)
		{
			if (ch == 'S')
			{
				cout << strName << "\n";
				return 0;
			}
		}
	}
	return 0;
}
