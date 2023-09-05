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
	
	char chLast = ' ';
	for(char ch : strWord)
	{
	    if(chLast != ch) cout << ch;
	    chLast = ch;
	}
	cout << "\n";
	return 0;
}
