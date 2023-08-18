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
	while (iN--)
	{
		int iNum;
		cin >> iNum;

		stack<int> stNum;

		while (iNum)
		{
			stNum.push(iNum % 3);
			iNum /= 3;
		}
		while (!stNum.empty())
		{
			cout << stNum.top();
			stNum.pop();
			cout << (stNum.empty() ? "\n" : " ");
		}
	}
	return 0;
}
