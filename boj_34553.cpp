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

	string strWord;
	cin >> strWord;


	long long lSum = 0;
	long long lNow = 0;

	char chBefore = 'a' - 1;
	for (char ch : strWord)
	{
		if (ch > chBefore)
		{
			++lNow;
		}
		else
		{
			lNow = 1;
		}
		lSum += lNow;
		chBefore = ch;
	}
	
	cout << lSum << "\n";
	return 0;
}
