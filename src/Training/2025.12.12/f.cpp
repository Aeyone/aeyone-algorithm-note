#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//dp好题
	int n;
	cin >> n;
	vector<pair<int, string>> dp(2001, {INF, "X"});
	auto check = [&](string &s)->bool{
		int m = s.size();
		vector<char> stk;
		for(int i = 0; i < m; i ++) {
			stk.push_back(s[i]);
			if(stk.back() == ')') {
				while(stk.back() != '('){
					stk.pop_back();
				}
				stk.pop_back();
			}
		}
		return (count(stk.begin(), stk.end(), '+') > 0);
	};
	dp[1] = {1, "1"};
	dp[11] = {2, "11"};
	dp[111] = {3, "111"};
	dp[1111] = {4, "1111"};
	for(int i = 1; i <= n; i ++) {
		auto [u, s1] = dp[i];
		int c1 = 2 * check(s1);
		for(int j = 1; j <= i; j ++) {
			auto [v, s2] = dp[j];
			int c2 = 2 * check(s2);
			if(i * j <= n) {
				auto &[e, s] = dp[i * j];
				if(e > u + v + 1 + c1 + c2) {
					e = u + v + 1 + c1 + c2;
					s = (c1 == 2 ? "(" + s1 + ")" : s1) + "*" + (c2 == 2 ? "(" + s2 + ")" : s2);
				}
			}
			if(i + j <= n) {
				auto &[e, s] = dp[i + j];
				if(e > u + v + 1) {
					e = u + v + 1;
					s = s1 + "+" + s2;
				}
			}
		}
	}
	cout << dp[n].second << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}