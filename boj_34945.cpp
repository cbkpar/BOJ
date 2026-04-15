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

	if (iN >= 6)
	{
		cout << "Success!" << "\n";
	}
	else
	{
		cout << "Oh My God!" << "\n";
	}
	return 0;
}
