#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int iN;
	cin >> iN;

	if (iN >= 380 && iN < 425)
	{
		cout << "Violet" << "\n";
	}
	else if (iN >= 425 && iN < 450)
	{
		cout << "Indigo" << "\n";
	}
	else if (iN >= 450 && iN < 495)
	{
		cout << "Blue" << "\n";
	}
	else if (iN >= 495 && iN < 570)
	{
		cout << "Green" << "\n";
	}
	else if (iN >= 570 && iN < 590)
	{
		cout << "Yellow" << "\n";
	}
	else if (iN >= 590 && iN < 620)
	{
		cout << "Orange" << "\n";
	}
	else if (iN >= 620 && iN <= 780)
	{
		cout << "Red" << "\n";
	}

	return 0;
}
