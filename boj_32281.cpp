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

	long long lAns = 0;
	long long lTemp = 0;

	for (int i = 0; i < iN; ++i)
	{
		if (strWord[i] == '1')
		{
			++lTemp;
		}
		else
		{
			lTemp = 0;
		}
		lAns += lTemp;
	}

	cout << lAns << "\n";
	return 0;
}
