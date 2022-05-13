#include <iostream>

using namespace std;

int main()
{
	auto Mulitply = [](int iN)->long long {
		long long llN = 1;
		while (iN--)
		{
			long long llTemp;
			cin >> llTemp;
			llN *= llTemp;
		}
		return llN;
	};
	long long llAnswer = (Mulitply(2) + Mulitply(2)) * (Mulitply(3));
	cout << llAnswer << endl;
	return 0;
}
