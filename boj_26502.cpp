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
	cin.ignore();
	for (int i = 0;i < iN;++i)
	{
		string strWord;
		getline(cin, strWord);

		for (char ch : strWord)
		{
			switch (ch)
			{
			case 'a': cout << "e"; break;
			case 'e': cout << "i"; break;
			case 'i': cout << "o"; break;
			case 'o': cout << "u"; break;
			case 'u': cout << "y"; break;
			case 'y': cout << "a"; break;

			case 'A': cout << "E"; break;
			case 'E': cout << "I"; break;
			case 'I': cout << "O"; break;
			case 'O': cout << "U"; break;
			case 'U': cout << "Y"; break;
			case 'Y': cout << "A"; break;

			default:
				cout << ch;
				break;
			}
		}
		cout << "\n";
	}

	return 0;
}
