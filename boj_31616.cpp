#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arrWeight[7] = { 100,50,20,10,5,2,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	string strWord;
	cin >> strWord;

	bool bPossible = true;
	for (int i = 1;i < iN;++i)
	{
		if (strWord[i - 1] != strWord[i])
		{
			bPossible = false;
		}
	}

	cout << (bPossible ? "Yes" : "No") << "\n";
	return 0;
}
