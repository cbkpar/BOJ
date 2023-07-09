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

	string strAns = "molu";

	string strWord;
	cin >> strWord;

	if (strWord == "fdsajkl;") strAns = "in-out";
	if (strWord == "jkl;fdsa") strAns = "in-out";
	if (strWord == "asdf;lkj") strAns = "out-in";
	if (strWord == ";lkjasdf") strAns = "out-in";
	if (strWord == "asdfjkl;") strAns = "stairs";
	if (strWord == ";lkjfdsa") strAns = "reverse";

	cout << strAns << "\n";
	return 0;
}
