#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int q;
	cin >> q;
	string s;
	cin >> s;
	int n = s.size();
	while (q --) {
		int c;
		cin >> c;
		if (c == 1) {
			string str;
			cin >> str;
			vector<int> pos;
			for (int i = 0; i + str.size() - 1 < n; i ++) {
				bool ok = true;
				for (int j = 0; j < str.size(); j ++) {
					ok &= (s[i + j] == str[j]);
				}
				if (ok) {
					pos.push_back(i);
				}
				if (pos.size() == 3) {
					break;
				}
			}
			if (pos.size() == 0) {
				cout << -1 << '\n';
			} else {
				for (int i = 0; i < pos.size() - 1; i ++) {
					cout << pos[i] << ' ';
				}
				cout << pos.back() << '\n';
			}
		} else if (c == 2) {
			int p;
			string str;
			cin >> p;
			cin >> str;
			s = s.substr(0, p) + str + s.substr(p, n - p);
			cout << s << '\n';
		} else if (c == 3) {
			int l, r;
			cin >> l >> r;
			reverse(s.begin() + l, s.begin() + r + 1);
			cout << s << '\n';
		}
		n = s.size();
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}