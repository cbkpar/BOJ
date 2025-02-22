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
		if (ch == 'J') cout << "O";
		if (ch == 'O') cout << "I";
		if (ch == 'I') cout << "J";
	}
	cout << "\n";
	return 0;
}
