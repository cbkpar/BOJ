#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float fWeight;
	float fHeight;

	cin >> fWeight >> fHeight;

	float BMI = fWeight / (fHeight * fHeight);
	if (BMI > 25.0f)
	{
		cout << "Overweight\n";
	}
	else if (BMI >= 18.5f)
	{
		cout << "Normal weight\n";
	}
	else
	{
		cout << "Underweight\n";
	}

	return 0;
}
