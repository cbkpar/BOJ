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

	int iT;
	cin >> iT;
	while (iT-- > 0)
	{
		int iK;
		cin >> iK;

		string strCode;
		cin >> strCode;

		for (char ch : strCode)
		{
			int iNum = ch - '0';
			iNum = (iNum + iK) % 10;
			cout << (char)(iNum + '0');
		}
		cout << "\n";
	}

	return 0;
}
