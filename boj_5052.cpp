#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct trie
{
	trie* ch[10];
	bool bEnd = false;

	trie()
	{
		for (int i = 0; i < 10; ++i) ch[i] = nullptr;
	}

	~trie()
	{
		for (int i = 0; i < 10; ++i) if (ch[i]) delete ch[i];
	}

	void Insert(string str)
	{
		trie* t = this;
		for (char c : str)
		{
			if (t->ch[c - '0'] == nullptr)
			{
				t->ch[c - '0'] = new trie();
			}
			t = t->ch[c - '0'];
		}
		t->bEnd = true;
	}

	bool Find(string str)
	{
		trie* t = this;
		for (char c : str)
		{
			if (t->ch[c - '0'] == nullptr) return false;
			if (t->ch[c - '0']->bEnd) return true;
			t = t->ch[c - '0'];
		}
		return true;
	}
}TRIE;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iT;
	cin >> iT;
	while (iT--)
	{
		TRIE trie;
		int iN;
		cin >> iN;

		bool bPossible = true;
		while (iN--)
		{
			string strNum;
			cin >> strNum;
			if (trie.Find(strNum))
			{
				bPossible = false;
			}
			trie.Insert(strNum);
		}
		cout << (bPossible ? "YES\n" : "NO\n");
	}
	return 0;
}
