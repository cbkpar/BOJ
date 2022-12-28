#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iA, iB, iC;
	string strOperator1, strOperator2;

	cin >> iA >> strOperator1 >> iB >> strOperator2 >> iC;
	if (iA + iB == iC)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
