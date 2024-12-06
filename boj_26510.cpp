#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	while (cin >> strWord)
	{
		int iNum = strWord[0] - '0';
		for (int i = 0;i < iNum;++i)
		{
			for (int j = 0;j < i;++j)
			{

				cout << " ";
			}
			cout << "*";
			if (i == iNum - 1)
			{
				cout << "\n";
				break;
			}
			for (int j = 0;j < (iNum - 1) * 2 - i * 2 - 1;++j)
			{
				cout << " ";
			}
			cout << "*\n";
		}
	}
	return 0;
}
