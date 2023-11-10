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

	while (true)
	{
		string strWord;
		cin >> strWord;

		if (strWord == "0") break;

		int iNum = 0;
		for (char ch : strWord)
		{
			iNum *= 10;
			iNum += ch - '0';
			iNum %= 42;
		}

		if (iNum == 0)
		{
			cout << "PREMIADO" << "\n";
		}
		else
		{
			cout << "TENTE NOVAMENTE" << "\n";
		}
	}
	return 0;
}
