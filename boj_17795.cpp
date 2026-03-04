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

	string strNum;
	cin >> strNum;

	int iLen = strNum.length();

	if (iLen == 1)
	{
		cout << strNum << "\n";
	}
	else
	{
		if (strNum[1] <= '4')
		{
			cout << strNum[0];
			for (int i = 1;i < iLen;++i)
			{
				cout << "0";
			}
			cout << "\n";
		}
		else
		{
			if (strNum[0] == '9')
			{
				cout << "10";
			}
			else
			{
				cout << (char)(strNum[0] + 1);
			}
			for (int i = 1;i < iLen;++i)
			{
				cout << "0";
			}
			cout << "\n";
		}
	}

	return 0;
}
