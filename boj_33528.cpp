#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string strWord;
	cin >> strWord;

	for (int i = 0;i < 26;++i)
	{
		for (char ch : strWord)
		{
			int iNow = ch - 'A';
			int iNext = (iNow - i + 26) % 26;
			cout << (char)(iNext + 'A');
		}
		cout << "\n";
	}

	return 0;
}
