#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

template<typename T> bool cmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }
template<typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

void solve() {
	int n, k;
	cin >> n >> k;
	vector<string> a(k);
	vector vis(n, vector<int>(26));
	for (int i = 0; i < k; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < k; j ++) {
			vis[i][a[j][i] - 'a'] = true;
		}
	}
	auto check = [&](int len)->pair<int, string>{
		vector res(len, vector<int>(26, 1));
		string s;
		for (int i = 0; i < len; i ++) {
			for (int j = i; j < n; j += len) {
				for (int k = 0; k < 26; k ++) {
					res[i][k] &= vis[j][k];
				}
			}
			bool ok = false;
			for (int k = 0; k < 26; k ++) {
				if (res[i][k]) {
					ok = true;
					s.push_back(char('a' + k));
					break;
				}
			}
			if (!ok) {
				return {INF, "x"};
			}
		}
		string ss;
		for (int i = 0; i < n; i += len) {
			ss += s;
		}
		return {len, ss};
	};
	pair<int, string> ans = {INF, ""};
	for (int i = 1; i <= n / i; i ++) {
		if (n % i == 0) {
			cmin(ans, check(i));
			if (n / i != i) {
				cmin(ans, check(n / i));
			}
		}
	}
	cout << ans.second << '\n';
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