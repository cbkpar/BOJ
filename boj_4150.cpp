#include <iostream>

using namespace std;

int main(void)
{
	int prev[1001] = { 0, };
	int next[1001] = { 0, };
	int n;
	cin >> n;
	prev[0] = next[0] = 1;
	for (int i = 3; i <= n; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			int tmp = next[j];
			next[j] += prev[j];
			if (next[j] >= 10) {
				next[j] -= 10;
				++prev[j + 1];
			}
			prev[j] = tmp;
		}
	}
	for (int i = 1000; i >= 0; --i) {
		if (!next[i]) continue;
		for (int j = i; j >= 0; --j) {
			cout << next[j];
		}
		break;
	}
	return 0;
}
