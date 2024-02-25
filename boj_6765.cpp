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
		for (int j = 0;j < iN;++j)
		{
			cout << "*";
		}
		for (int j = 0;j < iN;++j)
		{
			cout << "x";
		}
		for (int j = 0;j < iN;++j)
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			cout << " ";
		}
		for (int j = 0;j < iN;++j)
		{
			cout << "x";
		}
		for (int j = 0;j < iN;++j)
		{
			cout << "x";
		}
		cout << "\n";
	}
	for (int i = 0;i < iN;++i)
	{
		for (int j = 0;j < iN;++j)
		{
			cout << "*";
		}
		for (int j = 0;j < iN;++j)
		{
			cout << " ";
		}
		for (int j = 0;j < iN;++j)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}
