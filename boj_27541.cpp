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

	if (strWord[iN - 1] == 'G')
	{
		for (int i = 0; i < iN - 1; ++i) cout << strWord[i];
		cout << "\n";
	}
	else
	{
		cout << strWord << "G\n";
	}

	return 0;
}
