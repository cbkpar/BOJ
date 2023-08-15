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

	vector<string> vecWord(3, "");
	for (int i = 0; i < 3; ++i) cin >> vecWord[i];

	long long lAns = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (vecWord[i][0] >= '0' && vecWord[i][0] <= '9')
		{
			for (char ch : vecWord[i])
			{
				lAns *= 10;
				lAns += (ch - '0');
			}
			lAns += 3 - i;
			break;
		}
	}
	if (lAns % 15 == 0)
	{
		cout << "FizzBuzz" << "\n";
	}
	else if (lAns % 3 == 0)
	{
		cout << "Fizz" << "\n";
	}
	else if (lAns % 5 == 0)
	{
		cout << "Buzz" << "\n";
	}
	else
	{
		cout << lAns << "\n";
	}
	return 0;
}
