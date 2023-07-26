#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		set<string> setName;
		int iN;
		cin >> iN;
		while (iN--)
		{
			string strName;
			cin >> strName;
			setName.insert(strName);
		}
		cout << setName.size() << "\n";
	}
	return 0;
}
