#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Printer
{
public:
	Printer() {};
	Printer(const string& strNum) : m_Num(strNum) {};
	~Printer() {};

	void Print() const
	{
		bool bFirst = true;
		for (const char& ch : m_Num)
		{
			if (!bFirst) cout << "\n";
			switch (ch)
			{
			case '0':
				cout << "0000" << "\n";
				cout << "0  0" << "\n";
				cout << "0  0" << "\n";
				cout << "0  0" << "\n";
				cout << "0000" << "\n";
				break;
			case '1':
				cout << "   1" << "\n";
				cout << "   1" << "\n";
				cout << "   1" << "\n";
				cout << "   1" << "\n";
				cout << "   1" << "\n";
				break;
			case '2':
				cout << "2222" << "\n";
				cout << "   2" << "\n";
				cout << "2222" << "\n";
				cout << "2" << "\n";
				cout << "2222" << "\n";
				break;
			case '3':
				cout << "3333" << "\n";
				cout << "   3" << "\n";
				cout << "3333" << "\n";
				cout << "   3" << "\n";
				cout << "3333" << "\n";
				break;
			case '4':
				cout << "4  4" << "\n";
				cout << "4  4" << "\n";
				cout << "4444" << "\n";
				cout << "   4" << "\n";
				cout << "   4" << "\n";
				break;
			case '5':
				cout << "5555" << "\n";
				cout << "5" << "\n";
				cout << "5555" << "\n";
				cout << "   5" << "\n";
				cout << "5555" << "\n";
				break;
			case '6':
				cout << "6666" << "\n";
				cout << "6" << "\n";
				cout << "6666" << "\n";
				cout << "6  6" << "\n";
				cout << "6666" << "\n";
				break;
			case '7':
				cout << "7777" << "\n";
				cout << "   7" << "\n";
				cout << "   7" << "\n";
				cout << "   7" << "\n";
				cout << "   7" << "\n";
				break;
			case '8':
				cout << "8888" << "\n";
				cout << "8  8" << "\n";
				cout << "8888" << "\n";
				cout << "8  8" << "\n";
				cout << "8888" << "\n";
				break;
			case '9':
				cout << "9999" << "\n";
				cout << "9  9" << "\n";
				cout << "9999" << "\n";
				cout << "   9" << "\n";
				cout << "   9" << "\n";
				break;
			default:
				break;
			}
			bFirst = false;
		}
	}

private:
	string m_Num;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string strNum;
	cin >> strNum;

	Printer(strNum).Print();
	return 0;
}
