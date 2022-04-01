#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int leftMax = 0;
	int rightMin = 100000;
	cin >> n;
	while (n--)
	{
		int s, e;
		cin >> s >> e;
		leftMax = max(leftMax, s);
		rightMin = min(rightMin, e);
	}
	cout << (leftMax > rightMin ? leftMax - rightMin : 0) << endl;
	return 0;
}
