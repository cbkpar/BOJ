#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	set<string> setBirth;
	
	while (iN--)
	{
		string strBirth;
		cin >> strBirth;

		setBirth.insert(strBirth);
	}

	cout << setBirth.size() << "\n";
	return 0;
}
