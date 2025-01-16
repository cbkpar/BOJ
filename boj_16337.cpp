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

	vector<string> vecShape(3, "");
	for (int i = 0;i < 3;++i)
	{
		cin >> vecShape[i];
	}

	int iAns = -1;
	if (vecShape[0] == ":::" && vecShape[1] == ":o:" && vecShape[2] == ":::") iAns = 1;
	if (vecShape[0] == "o::" && vecShape[1] == ":::" && vecShape[2] == "::o") iAns = 2;
	if (vecShape[0] == "::o" && vecShape[1] == ":::" && vecShape[2] == "o::") iAns = 2;
	if (vecShape[0] == "o::" && vecShape[1] == ":o:" && vecShape[2] == "::o") iAns = 3;
	if (vecShape[0] == "::o" && vecShape[1] == ":o:" && vecShape[2] == "o::") iAns = 3;
	if (vecShape[0] == "o:o" && vecShape[1] == ":::" && vecShape[2] == "o:o") iAns = 4;
	if (vecShape[0] == "o:o" && vecShape[1] == ":o:" && vecShape[2] == "o:o") iAns = 5;
	if (vecShape[0] == "ooo" && vecShape[1] == ":::" && vecShape[2] == "ooo") iAns = 6;
	if (vecShape[0] == "o:o" && vecShape[1] == "o:o" && vecShape[2] == "o:o") iAns = 6;

	if (iAns == -1)
	{
		cout << "unknown" << "\n";
	}
	else
	{
		cout << iAns << "\n";
	}
	return 0;
}
