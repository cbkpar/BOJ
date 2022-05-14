#include <iostream>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	auto PrintRepeatHead = [](int _iN)->void {
		while (-2 < _iN-- )
		{
			cout << '@';
		}
		cout << endl;
	};

	auto PrintRepeatBody = [](int _iN)->void {
		for (int i = 0; i < _iN; ++i)
		{
			cout << '@';
			[](int _iN)->void {while (_iN--) { cout << ' '; }}(_iN);
			cout << '@' << endl;
		}
	};

	PrintRepeatHead(iN);
	PrintRepeatBody(iN);
	PrintRepeatHead(iN);
	return 0;
}
