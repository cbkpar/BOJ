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
	
	if (strWord[0] == '1' || strWord[2] == '1')
	{
		cout << "1" << "\n";
	}
	else if (strWord == "(1)")
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "2" << "\n";
	}

	return 0;
}
