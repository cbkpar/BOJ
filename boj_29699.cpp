#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string strWord = "WelcomeToSMUPC";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	cout << strWord[(iN - 1) % 14] << "\n";
	return 0;
}
