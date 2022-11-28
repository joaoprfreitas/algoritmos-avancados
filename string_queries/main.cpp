#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Trie {
	map<char, Trie> mp;
	int cnt = 0; // qts string passaram aqui
	int end = 0; // qts strings terminaram aqui

	void add(string& s, int i = 0) {
		cnt++;
		if (i < (int) s.size()) {
			mp[s[i]].add(s, i + 1);
		} else end++;
	}
	
	void remove(string& s, int i = 0) {
        cnt--;
		if (i < (int) s.size()) {
			mp[s[i]].remove(s, i + 1);
		} else end--;
  }

  int search(string& s, int i = 0) {
    int k = 0;
    if (i == (int) s.size()) return cnt;
    if (mp.count(s[i])) return k + mp[s[i]].search(s, i + 1);
    return k;
  }
};

int main() {
    Trie root;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        string s;
        cin >> t >> s;

        if (t == 1) root.add(s);
        else if (t == 2) root.remove(s);
        else cout << root.search(s) << endl;

    }
}