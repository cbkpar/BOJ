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

	int iN;
	cin >> iN;

	for (int i = 0;i < iN;++i)
	{
		string strWord;
		cin >> strWord;
		if (strWord == ".-") cout << "A";
		if (strWord == "-...") cout << "B";
		if (strWord == "-.-.") cout << "C";
		if (strWord == "-..") cout << "D";
		if (strWord == ".") cout << "E";
		if (strWord == "..-.") cout << "F";
		if (strWord == "--.") cout << "G";
		if (strWord == "....") cout << "H";
		if (strWord == "..") cout << "I";
		if (strWord == ".---") cout << "J";
		if (strWord == "-.-") cout << "K";
		if (strWord == ".-..") cout << "L";
		if (strWord == "--") cout << "M";
		if (strWord == "-.") cout << "N";
		if (strWord == "---") cout << "O";
		if (strWord == ".--.") cout << "P";
		if (strWord == "--.-") cout << "Q";
		if (strWord == ".-.") cout << "R";
		if (strWord == "...") cout << "S";
		if (strWord == "-") cout << "T";
		if (strWord == "..-") cout << "U";
		if (strWord == "...-") cout << "V";
		if (strWord == ".--") cout << "W";
		if (strWord == "-..-") cout << "X";
		if (strWord == "-.--") cout << "Y";
		if (strWord == "--..") cout << "Z";
		if (strWord == ".----") cout << "1";
		if (strWord == "..---") cout << "2";
		if (strWord == "...--") cout << "3";
		if (strWord == "....-") cout << "4";
		if (strWord == ".....") cout << "5";
		if (strWord == "-....") cout << "6";
		if (strWord == "--...") cout << "7";
		if (strWord == "---..") cout << "8";
		if (strWord == "----.") cout << "9";
		if (strWord == "-----") cout << "0";
		if (strWord == "--..--") cout << ",";
		if (strWord == ".-.-.-") cout << ".";
		if (strWord == "..--..") cout << "?";
		if (strWord == "---...") cout << ":";
		if (strWord == "-....-") cout << "-";
		if (strWord == ".--.-.") cout << "@";
	}
	cout << "\n";

	return 0;
}
