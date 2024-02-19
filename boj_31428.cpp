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

	vector<int> vecCount(26, 0);
	for (int i = 0;i < iN;++i)
	{
		string strMajor;
		cin >> strMajor;
		++vecCount[strMajor[0] - 'A'];
	}

	string strAlice;
	cin >> strAlice;

	cout << vecCount[strAlice[0] - 'A'] << "\n";
	return 0;
}
