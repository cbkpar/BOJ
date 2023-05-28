#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string g_vecWord[26] = { "@", "8", "(", "|)", "3",
"#", "6", "[-]", "|", "_|",
"|<", "1", "[]\\/[]", "[]\\[]", "0",
"|D", "(,)", "|Z", "$", "']['",
"|_|", "\\/", "\\/\\/", "}{", "`/", "2" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strWord;
	getline(cin, strWord);

	string strAns = "";

	for (char ch : strWord)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			strAns += g_vecWord[ch - 'a'];
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			strAns += g_vecWord[ch - 'A'];
		}
		else
		{
			strAns += ch;
		}
	}
	cout << strAns << "\n";
	return 0;
}
