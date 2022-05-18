#include <iostream>

using namespace std;

int main()
{
	unsigned long long llN;
	cin >> llN;
	if (0 == llN)
	{
		cout << "0" << endl;
		return 0;
	}
	unsigned long long llLeft = 1;
	unsigned long long llRight = 3037000500L;
	unsigned long long llAnswer = 3037000500L;
	while (llLeft <= llRight)
	{
		unsigned long long llMid = (llLeft + llRight) / 2;
		unsigned long long llSquare = llMid * llMid;
		if (llSquare >= llN)
		{
			llAnswer = llMid;
			llRight = llMid - 1;
		}
		else
		{
			llLeft = llMid + 1;
		}
	}
	cout << llAnswer << endl;
	return 0;
}
