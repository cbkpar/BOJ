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

	string strScore;
	cin >> strScore;

	if (strScore == "miss")
	{
		cout << "0" << "\n";
	}
	if (strScore == "bad")
	{
		cout << iN * 200 << "\n";
	}
	if (strScore == "cool")
	{
		cout << iN * 400 << "\n";
	}
	if (strScore == "great")
	{
		cout << iN * 600 << "\n";
	}
	if (strScore == "perfect")
	{
		cout << iN * 1000 << "\n";
	}

	return 0;
}
