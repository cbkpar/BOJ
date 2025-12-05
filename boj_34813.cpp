#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strName;
	cin >> strName;

	if (strName[0] == 'F') cout << "Foundation" << "\n";
	if (strName[0] == 'C') cout << "Claves" << "\n";
	if (strName[0] == 'V') cout << "Veritas" << "\n";
	if (strName[0] == 'E') cout << "Exploration" << "\n";


	return 0;

}
