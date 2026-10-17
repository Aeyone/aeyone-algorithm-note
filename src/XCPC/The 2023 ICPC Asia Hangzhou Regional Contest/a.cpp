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
	map<string, int> id;
	vector<string> name(n), stats(n), uid;
	vector<char> prm(n);
	vector<int> t(n);
	int m = 0;

	for (int i = 0; i < n; i ++) {
		cin >> name[i] >> prm[i] >> t[i] >> stats[i];
		if (id.find(name[i]) == id.end()) {
			id[name[i]] = m ++;
			uid.push_back(name[i]);
		}
	}

	map<string, pair<int, int>> mp;
	map<pair<string, char>, int> ac;

	for (int i = 0; i < n; i ++) {
		if (ac[{name[i], prm[i]}] == 1) {
			continue;
		} else if (stats[i] == "accepted") {
			ac[{name[i], prm[i]}] = 1;
			mp[name[i]].first --;
			mp[name[i]].second += t[i];
			mp[name[i]].second -= ac[{name[i], prm[i]}];
		} else {
			ac[{name[i], prm[i]}] -= 20;
		}
	}

	vector<pair<int, int>> tot(m);
	vector<int> u(m);
	iota(u.begin(), u.end(), 0);

	for (auto [s, p] : mp) {
		tot[id[s]] = p;
	}

	sort(u.begin(), u.end(), [&](const int &a, const int &b)-> bool {
		return tot[a] < tot[b];
	});

	// for (int i = 0; i < m; i ++) {
	// 	cout << u[i] << ' ';
	// }
	// cout << '\n';

	int cnt = 0;
	for (auto e : u) {
		cnt += (tot[e].first < 0);
	}

	int line = min((cnt + 9) / 10, 35);

	vector<string> ans;
	for (int i = 0; i < line; i ++) {
		int j = u[i];
		ans.push_back(uid[j]);
	}

	for (int i = 0; i < n; i ++) {
		if (stats[i] == "rejected") {

		}
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