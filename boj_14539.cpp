#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int iT;
	cin >> iT;
	for (int t = 1;t <= iT;++t)
	{
		int iN, iM, iC, iR;
		cin >> iR >> iC >> iM >> iN;

		cout << "Case #" << t << ":" << "\n";
		cout << "+";
		for (int p = 0; p < iC;++p)
		{
			for (int q = 0;q < iM;++q)
			{
				cout << "-";
			}
			cout << "+";
		}
		cout << "\n";
		for (int i = 0;i < iR;++i)
		{
			for (int j = 0;j < iN;++j)
			{
				cout << "|";
				for (int p = 0; p < iC;++p)
				{
					for (int q = 0;q < iM;++q)
					{
						cout << "*";
					}
					cout << "|";
				}
				cout << "\n";
			}
			cout << "+";
			for (int p = 0; p < iC;++p)
			{
				for (int q = 0;q < iM;++q)
				{
					cout << "-";
				}
				cout << "+";
			}
			cout << "\n";
		}
	}

	return 0;
}
