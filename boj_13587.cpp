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
	cin >> strWord;

	string strA = "";
	string strB = "";

	for (char ch : strWord)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			strA = strA + char(ch);
			strB = (char)ch + strB;
		}
	}

	if (strA == strB)
	{
		cout << "S" << "\n";
	}
	else
	{
		cout << "N" << "\n";
	}
	return 0;
}
