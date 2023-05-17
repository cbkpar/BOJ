#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<string> setWord;
	bool bDuplicate = false;

	string strWord;
	while (cin >> strWord)
	{
		if (setWord.find(strWord) != setWord.end())
		{
			bDuplicate = true;
			break;
		}
		else
		{
			setWord.insert(strWord);
		}
	}
	cout << (bDuplicate ? "no\n" : "yes\n");
	return 0;
}
