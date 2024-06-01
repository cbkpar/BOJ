#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsPalindrome(string strWord)
{
	int iLen = strWord.length();
	for(int i=0;i<iLen;++i)
	{
		if(strWord[i] != strWord[iLen-1-i])
		{
			return false;
		}
	}

	return true;
}

bool IsReverse(string strWord)
{
	int iLen = strWord.length();
	for(int i=0;i<iLen;++i)
	{
		switch(strWord[i])
		{
		case 'A' :
			if(strWord[iLen-1-i] != 'A')
			{
				return false;
			}
			break;
		case 'E' :
			if(strWord[iLen-1-i] != '3')
			{
				return false;
			}
			break;
		case 'H' :
			if(strWord[iLen-1-i] != 'H')
			{
				return false;
			}
			break;
		case 'I' :
			if(strWord[iLen-1-i] != 'I')
			{
				return false;
			}
			break;
		case 'J' :
			if(strWord[iLen-1-i] != 'L')
			{
				return false;
			}
			break;
		case 'L' :
			if(strWord[iLen-1-i] != 'J')
			{
				return false;
			}
			break;
		case 'M' :
			if(strWord[iLen-1-i] != 'M')
			{
				return false;
			}
			break;
		case 'O' :
			if(strWord[iLen-1-i] != 'O')
			{
				return false;
			}
			break;
		case 'S' :
			if(strWord[iLen-1-i] != '2')
			{
				return false;
			}
			break;
		case 'T' :
			if(strWord[iLen-1-i] != 'T')
			{
				return false;
			}
			break;
		case 'U' :
			if(strWord[iLen-1-i] != 'U')
			{
				return false;
			}
			break;
		case 'V' :
			if(strWord[iLen-1-i] != 'V')
			{
				return false;
			}
			break;
		case 'W' :
			if(strWord[iLen-1-i] != 'W')
			{
				return false;
			}
			break;
		case 'X' :
			if(strWord[iLen-1-i] != 'X')
			{
				return false;
			}
			break;
		case 'Y' :
			if(strWord[iLen-1-i] != 'Y')
			{
				return false;
			}
			break;
		case 'Z' :
			if(strWord[iLen-1-i] != '5')
			{
				return false;
			}
			break;
		case '1' :
			if(strWord[iLen-1-i] != '1')
			{
				return false;
			}
			break;
		case '2' :
			if(strWord[iLen-1-i] != 'S')
			{
				return false;
			}
			break;
		case '3' :
			if(strWord[iLen-1-i] != 'E')
			{
				return false;
			}
			break;
		case '5' :
			if(strWord[iLen-1-i] != 'Z')
			{
				return false;
			}
			break;
		case '8' :
			if(strWord[iLen-1-i] != '8')
			{
				return false;
			}
			break;
		default:
			return false;
			}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool bFirst = true;
	string strWord;
	
	while(cin >> strWord)
	{
		if(!bFirst) cout << "\n";
		bool bPalindrome = IsPalindrome(strWord);
		bool bReverse = IsReverse(strWord);

		if(!bPalindrome && !bReverse)
		{
			cout << strWord << " -- is not a palindrome.\n";
		}
		if(bPalindrome && !bReverse)
		{
			cout << strWord << " -- is a palindrome.\n";
		}
		if(!bPalindrome && bReverse)
		{
			cout << strWord << " -- is a mirrored string.\n";
		}
		if(bPalindrome && bReverse)
		{
			cout << strWord << " -- is a mirrored palindrome.\n";
		}
		bFirst = false;
	}

	return 0;
}
