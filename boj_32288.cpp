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

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	for (char ch : strWord)
	{

		if (ch >= 'a' && ch <= 'z')
		{
			cout << (char)(ch - 'a' + 'A');
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			cout << (char)(ch - 'A' + 'a');
		}
		else
		{
			cout << ch;
		}
	}

	cout << "\n";
	return 0;
}
