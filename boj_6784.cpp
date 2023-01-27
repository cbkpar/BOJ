#include <iostream>

using namespace std;

string ArrCheck[10000];
string ArrAnswer[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN;
	cin >> iN;

	int iAnswer = 0;

	for (int i = 0; i < iN; ++i) cin >> ArrCheck[i];
	for (int i = 0; i < iN; ++i) cin >> ArrAnswer[i];
	for (int i = 0; i < iN; ++i) if (ArrCheck[i] == ArrAnswer[i]) ++iAnswer;

	cout << iAnswer << "\n";
	return 0;
}
