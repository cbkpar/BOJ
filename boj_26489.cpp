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

	int iAns = 0;
	string strWord;
	while (getline(cin, strWord))
	{
		++iAns;
	}

	cout << iAns << "\n";
	return 0;
}
