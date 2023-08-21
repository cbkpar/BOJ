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

	if (strWord == "M") cout << "MatKor" << "\n";
	if (strWord == "W") cout << "WiCys" << "\n";
	if (strWord == "C") cout << "CyKor" << "\n";
	if (strWord == "A") cout << "AlKor" << "\n";
	if (strWord == "$") cout << "$clear" << "\n";

	return 0;
}
