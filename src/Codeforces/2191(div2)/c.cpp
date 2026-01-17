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
	while (s.size() && s.back() == '1') {
		s.pop_back();
	}
	if (!s.size() || count(s.begin(), s.end(), '0') == s.size()) {
		cout << "Bob" << '\n';
		return;
	}
	cout << "Alice" << '\n';
	vector<int> ans;
	for (int l = 0, r = s.size() - 1; l < r; l ++, r --) {
		while (l < s.size() && s[l] == '0') {
			l ++;
		}
		while (r >= 0 && s[r] == '1') {
			r --;
		}
		if (l < r) {
			ans.push_back(l);
			ans.push_back(r);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto e : ans) {
		cout << e + 1 << ' ';
	}
	cout << '\n';
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