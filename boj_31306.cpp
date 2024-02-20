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

	int iVowel = 0;
	int iY = 0;

	for (char ch : strWord)
	{
		if (ch == 'a') ++iVowel;
		if (ch == 'e') ++iVowel;
		if (ch == 'i') ++iVowel;
		if (ch == 'o') ++iVowel;
		if (ch == 'u') ++iVowel;
		if (ch == 'y') ++iY;
	}

	cout << iVowel << " " << (iVowel + iY) << "\n";
	return 0;
}
