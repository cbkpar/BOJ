#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> mapWord;
	mapWord.insert({ "CU", "see you" });
	mapWord.insert({ ":-)", "I’m happy" });
	mapWord.insert({ ":-(", "I’m unhappy" });
	mapWord.insert({ ";-)", "wink" });
	mapWord.insert({ ":-P", "stick out my tongue" });
	mapWord.insert({ "(~.~)", "sleepy" });
	mapWord.insert({ "TA", "totally awesome" });
	mapWord.insert({ "CCC", "Canadian Computing Competition" });
	mapWord.insert({ "CUZ", "because" });
	mapWord.insert({ "TY", "thank-you" });
	mapWord.insert({ "YW", "you’re welcome" });
	mapWord.insert({ "TTYL", "talk to you later" });

	while (true)
	{
		string strWord;
		cin >> strWord;

		if (mapWord.find(strWord) == mapWord.end())
		{
			cout << strWord << "\n";
		}
		else
		{
			cout << mapWord[strWord] << "\n";
		}
		if (strWord == "TTYL") break;
	}

	return 0;
}
