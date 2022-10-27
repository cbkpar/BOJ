#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	for (int i = 1; i <= iN; ++i)
	{
		string strA, strB;
		cin >> strA >> strB;
		cout << "Case " << i << ": " << strB << ", " << strA << "\n";
	}
	return 0;
}
