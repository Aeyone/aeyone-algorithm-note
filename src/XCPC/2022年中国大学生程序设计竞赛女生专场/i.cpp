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
	const int N = 5e5 + 10;
	vector son(2, vector(N, vector<int>(26)));
	vector cnt(2, vector<int>(N));
	int idx[2] = {1, 1};

	auto insert = [&](int c, string s)->void{
		auto &sonn = son[c];
		auto &cntt = cnt[c];
		auto &idxx = idx[c];

		int p = 0;
		for (auto e : s) {
			int u = e - 'a';
			if (!sonn[p][u]) {
				sonn[p][u] = idxx ++;
			}
			p = sonn[p][u];
		}
		cntt[p] = s.size();
	};
	
	auto query = [&](int c, string s)->vector<int> {
		auto &sonn = son[c];
		auto &cntt = cnt[c];

		int p = 0;
		vector<int> tot;
		for (auto e : s) {
			int u = e - 'a';
			if (!sonn[p][u]) {
				return tot;
			}
			p = sonn[p][u];
			if (cntt[p] > 0) {
				tot.push_back(cntt[p]);
			} 
		}
		return tot;
	};

	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		insert(0, a[i]);
	}
	int m;
	cin >> m;
	vector<string> b(m);
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
		insert(1, b[i]);
	}
	string s;
	cin >> s;
	int k = s.size();

	s = " " + s;

	vector dp(2, vector<int>(k + 1, INF)); // dp[0/1][i] 代表最后选的A/B，以i个位置结尾的贡献
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int i = 1; i <= k; i ++) {
		string suf = s.substr(i, k - i + 1);
		auto qa = query(0, suf);
		auto qb = query(1, suf);
		for (auto d : qa) {
			dp[0][i + d - 1] = min(dp[0][i + d - 1], dp[1][i - 1] + 1);
		}
		for (auto d : qb) {
			dp[1][i + d - 1] = min(dp[1][i + d - 1], dp[0][i - 1] + 1);
		}
	}
	int ans = min(dp[0][k], dp[1][k]);
	cout << (ans == INF ? -1 : ans) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}