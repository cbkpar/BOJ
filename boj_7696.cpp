#include <iostream>

using namespace std;

bool CheckRepeat(int n)
{
	bool chk[10] = { false };
	while (n)
	{
		int t = n % 10;
		if (chk[t])
		{
			return false;
		}
		chk[t] = true;
		n /= 10;
	}
	return true;
}

int main()
{
	int ans[1000001];
	int idx = 1;
	int number = 0;
	while (true)
	{
		number++;
		if (CheckRepeat(number))
		{
			ans[idx++] = number;
		}
		if (idx == 1000001) break;
	}
	while (true)
	{
		int num;
		cin >> num;
		if (0 == num)
		{
			break;
		}
		cout << ans[num] << endl;
	}
	return 0;
}
