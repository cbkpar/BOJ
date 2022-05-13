#include <iostream>

using namespace std;

int main()
{
	int iW1, iH1, iW2, iH2;
	cin >> iW1 >> iH1 >> iW2 >> iH2;
	int iAnswer = [=]()->int {
		return 2 * (iH1 + iH2 + 2 + [=]()->int {
			return (iW1 > iW2 ? iW1 : iW2); }());
	}();
	cout << iAnswer << endl;
	return 0;
}
