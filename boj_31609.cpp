#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> vecVisited(10, false);
	
	int iN;
	cin >> iN;
	for (int i = 0; i < iN; ++i)
	{
		int iNum;
		cin >> iNum;
		vecVisited[iNum] = true;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (vecVisited[i])
		{
			cout << i << "\n";
		}
	}
	return 0;
}
