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

	string strWord;
	
	while (getline(cin, strWord))
	{
		for (char ch : strWord)
		{
			switch (ch)
			{
			case 'i': cout << "e"; break;
			case 'e': cout << "i"; break;
			case 'I': cout << "E"; break;
			case 'E': cout << "I"; break;
			default: cout << ch; break;
			}
		}
		cout << "\n";
	}
	return 0;
}
