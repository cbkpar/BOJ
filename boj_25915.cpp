#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strCommand;
	cin >> strCommand;
	int iCount = abs(strCommand[0] - 'I');
	cout << (iCount + 84) << "\n";
	return 0;
}
