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
	string s, t;
	cin >> s >> t;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i < n; i ++) {
		cnt1 += (s[i] == ')' && s[i - 1] == '(');
		cnt2 += (t[i] == ')' && t[i - 1] == '(');
	}
	auto run = [&](string& s)-> int {
		vector<int> to(n), stk;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '(') {
				stk.push_back(i);
			} else {
				to[i] = stk.back();
				to[stk.back()] = i;
				stk.pop_back();
			}
		}
		int l = 0, r = n - 1;
		int ans = 0;
		while (l < r && r == to[l]) {
			l ++, r --;
			ans ++;
		}
		return ans;
	};

	if (cnt1 == cnt2 && run(s) == run(t)) {
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
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