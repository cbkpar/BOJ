#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iN;
	cin >> iN;
	list<string> listName[201];
	while (iN--)
	{
		int iAge;
		string strName;
		cin >> iAge >> strName;
		listName[iAge].emplace_back(strName);
	}
	for (int i = 1; i <= 200; ++i)
	{
		for (auto iter = listName[i].begin(); iter != listName[i].end(); ++iter)
		{
			cout << i << " " + (*iter) + "\n";
		}
	}
	return 0;
}
