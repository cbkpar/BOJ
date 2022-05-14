#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	cin >> str;
	for_each(str.rbegin(), str.rend(), [](char c) {cout << c; });
	return 0;
}
