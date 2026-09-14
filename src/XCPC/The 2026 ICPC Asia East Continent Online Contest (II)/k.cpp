#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 1);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] <= n) {
			cnt[a[i]] ++;
		}
	}
	int mex = 0;
	while (cnt[mex]) {
		mex ++;
	}
	sort(a.begin(), a.end());
	vector<int> b;
	int cur = 0;
	for (int i = 0; i < n; i ++) {
		if (cur == a[i]) {
			cur ++;
			continue;
		}
		b.push_back(a[i]);
	}

	auto v = b;
	v.erase(unique(v.begin(), v.end()), v.end());

	auto find = [&](int x) -> int {
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	};
	int m = v.size();
	v.push_back(INF);

	unordered_map<int, int> ans;

	vector<int> mp(m);
	for (auto &ee : b) mp[find(ee)] ++;

	for (auto &e : b) {
		vector<int> del;
		int t = mex;
		int k = t + e;

		while (1) {
			int idx1 = find(t), idx2 = find(k - t);
			if (v[idx1] == t && mp[idx1] > 0) {
				mp[idx1] --;
				del.push_back(idx1);
				t ++;
			} else if (v[idx2] == k - t && mp[idx2] > 0) {
				mp[idx2] --;
				del.push_back(idx2);
				t ++;
			} else {
				break;
			}
		}

		for (auto ee : del) {
			mp[ee] ++;
		}
		ans[k] = t;
	}	


	int q;
	cin >> q;
	int res = 0;
	while (q --) {
		int k;
		cin >> k;
		if (ans.find(k) == ans.end()) {
			res ^= mex;
		} else {
			res ^= ans[k];
		}
	}
	cout << res << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}