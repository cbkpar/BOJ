#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iN, iK;
	cin >> iN >> iK;

	string strLine;
	cin >> strLine;

	for (int i = 0;i < iN;++i)
	{
		if (i + 1 >= iK)
		{
			if (strLine[i] >= 'a' && strLine[i] <= 'z')
			{
				cout << (char)(strLine[i] - 'a' + 'A');
			}
			else
			{
				cout << (char)(strLine[i] - 'A' + 'a');
			}
		}
		else
		{
			cout << strLine[i];
		}
	}
	cout << "\n";
	return 0;
}
