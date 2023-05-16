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

	int iN;
	cin >> iN;

	bool bAns = true;
	for (int i = 0; i < iN; ++i)
	{
		string strReply;
		cin >> strReply;
		if (strReply == "LIE")
		{
			bAns = !bAns;
		}
	}
	cout << (bAns ? "TRUTH\n" : "LIE\n");
	return 0;
}
