#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
		long long lNum;
		cin >> lNum;
		if (lNum == 0)
		{
			cout << "0" << "\n";
		}
		else
		{
			stack<long long> stNum;
			while (lNum > 0)
			{
				stNum.push(lNum % 3);
				lNum /= 3;
			}
			while (!stNum.empty())
			{
				cout << stNum.top();
				stNum.pop();
			}
			cout << "\n";
		}
	}
}
