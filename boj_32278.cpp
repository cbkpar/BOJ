#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long lN;
	cin >> lN;

	if(lN >= -32768 && lN <= 32767)
	{
		cout  << "short" << "\n";
	}
	else if(lN >= -2147483648 && lN <= 2147483647)
	{
		cout  << "int" << "\n";
	}
	else
	{
		cout  << "long long" << "\n";
	}

	return 0;
}
