#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
*	模版题，差分后kmp，统计子串数量，注意w=1的时候特判
*/

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), da(n), db(m);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i > 0) {
			da[i] = a[i] - a[i - 1];
		}
	}
	for (int i = 0; i < m; i ++) {
		cin >> b[i];
		if (i > 0) {
			db[i] = b[i] - b[i - 1];
		}
	}
	if (m == 1) {
		cout << n << '\n';
		return;
	}
	int ans = 0;
	auto kmp = [&](vector<int> s, vector<int> p)->void {
		int n = p.size() - 1, m = s.size() - 1;
		vector<int> ne(n + 1);
		for (int i = 2, j = 0; i <= n; i ++) {
	        while(j && p[i] != p[j + 1]) {
	            j = ne[j];
	        }
	        if (p[i] == p[j + 1]) {
	            j ++;
	        }
	        ne[i] = j;
	    }
	    for (int i = 1, j = 0; i <= m; i ++) {
	        while (j && s[i] != p[j + 1]) {
	            j = ne[j];
	        }
	        if (s[i] == p[j + 1]) {
	            j ++;
	        }
	        if (j == n) {
	            j = ne[j];
	        	ans ++;
	        }
	    }
	};
	kmp(da, db);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}