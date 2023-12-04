#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main()
{
	set<string> setType;
	
	for (int i = 0;i < 4;++i)
	{
		string strType;
		cin >> strType;
		setType.insert(strType);
	}

	for (auto iter1 = setType.begin();iter1 != setType.end();++iter1)
	{
		for (auto iter2 = setType.begin();iter2 != setType.end();++iter2)
		{
			cout << *iter1 << " " << *iter2 << "\n";
		}
	}
	return 0;
}
