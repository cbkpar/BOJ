#include <iostream>
# <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, less<int>> pq;
	int iN;
	cin >> iN;
	while (iN--)
	{
		int iInput;
		cin >> iInput;
		if (0 == iInput) {
			if (0 == pq.size())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
		{
			while (iInput--)
			{
				int iM;
				cin >> iM;
				pq.push(iM);
			}
		}
	}
    return 0;
}
