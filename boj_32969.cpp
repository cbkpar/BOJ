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

	string strWord = "";
	string strTemp;
	bool bDigital = false;
	while (cin >> strTemp)
	{
		strWord = strWord + strTemp;
	}

	if (strWord.find("social") != string::npos) bDigital = true;
	if (strWord.find("history") != string::npos) bDigital = true;
	if (strWord.find("language") != string::npos) bDigital = true;
	if (strWord.find("literacy") != string::npos) bDigital = true;

	cout << (bDigital ? "digital humanities" : "public bigdata") << "\n";
	return 0;
}
