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

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;

		cout << strWord << "DORO" << (i == iN - 1 ? "\n" : " ");
	}

	return 0;
}
