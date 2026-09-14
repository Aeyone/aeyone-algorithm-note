#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f

const int N = 5e5 + 10;
int son[N][26], cnt[N];

void solve () {
	int n;
	cin >> n;
	int idx = 0;
	
	vector<int> ans(n + 1, -INF);

	auto insert = [&](string s, int &val)-> void {
		int p = 0, dep = 0;
		cnt[p] ++;
		if (ans[cnt[p]] < dep) {
			if (ans[cnt[p]] != -INF) {
				val -= (ans[cnt[p]] ^ cnt[p]);
			}
			val += (dep ^ cnt[p]);
			ans[cnt[p]] = dep;
		}
		for (auto c : s) {
			int u = c - 'a';
			if (!son[p][u]) son[p][u] = ++ idx;
			p = son[p][u];
			dep ++;
			cnt[p] ++;
			if (ans[cnt[p]] < dep) {
				if (ans[cnt[p]] != -INF) {
					val -= (ans[cnt[p]] ^ cnt[p]);
				}
				val += (dep ^ cnt[p]);
				ans[cnt[p]] = dep;
			}
		}
	};

	int val = 0;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		insert(s, val);
		cout << val << '\n';
	}
}

signed main () {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}