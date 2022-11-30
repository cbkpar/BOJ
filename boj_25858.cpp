#include <iostream>
#include <string>

using namespace std;

int arr[30] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iD;
	cin >> iN >> iD;
	int iSum = 0;
	for (int i = 0; i < iN; ++i)
	{
		cin >> arr[i];
		iSum += arr[i];
	}
	for (int i = 0; i < iN; ++i)
	{
		cout << (iD / iSum * arr[i]) << "\n";
	}
	return 0;
}
