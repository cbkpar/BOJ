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

	for (int i = 0;i < iN - 1;++i)
	{
		if (strWord[i + 1] == 'J')
		{
			cout << strWord[i] << "\n";
		}
	}
	return 0;
}
