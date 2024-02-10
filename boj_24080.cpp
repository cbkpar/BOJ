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

	vector<int> vecCount(5, 0);
	for (char ch : strWord)
	{
		++vecCount[ch - 'A'];
	}

	int iCount = 0;
	for (int i = 0;i < 5;++i)
	{
		if (vecCount[i] > 0) ++iCount;
	}
	if (iCount >= 3)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}

	return 0;
}
