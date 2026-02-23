#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s.front() != s.back()) {
		cout << "empty" << '\n';
		return;
	}
	char c = (s.front() == '0' ? '1' : '0');
	int l = 0, r = n - 1;
	while (l < s.size() && s[l] != c) {
		l ++;
	}
	while (r >= 0 && s[r] != c) {
		r --;
	}
	vector<int> v;
	for (int i = 0; i < n; i ++) {
		if (s[i] == c) {
			v.push_back(i);
		}
	}
	int ans = min(l, n - r - 1);
	for (int i = 1; i < v.size(); i ++) {
		ans = min(ans, v[i] - v[i - 1] - 1);
	}
	if (ans == 0) {
		cout << "empty" << '\n';
	} else {
		cout << string(ans, s.front()) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}