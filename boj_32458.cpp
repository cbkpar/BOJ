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
	
	for (char ch : strWord)
	{
		if (ch == '.') break;
		cout << ch;
	}
	cout << "\n";
	return 0;
}
