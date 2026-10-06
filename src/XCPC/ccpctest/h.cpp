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
	array<int, 2> max = {0, 1};
	for (int i = 2; i <= n; i ++) {
		cout << "? " << 1 << ' ' << i << endl;
		int x;
		cin >> x;
		max = std::max(max, {x, i});
	}

	int root = max[1];
	vector<vector<int>> dis(n + 1);

	max = {0, root};
	for (int i = 1; i <= n; i ++) {
		cout << "? " << root << ' ' << i << endl;
		int x;
		cin >> x;
		dis[x].push_back(i);
		max = std::max(max, {x, i});
	}

	vector<array<int, 2>> ans;
	vector<int> vis(n + 1);
	for (int i = 0; i < n; i ++) {
		if (dis[i].size() == 1 && dis[i + 1].size() == 1) {
			vis[dis[i][0]] = 1;
			ans.push_back({dis[i][0], dis[i + 1][0]});
		} else {
			break;
		}
	}

	root = max[1];
	vector<vector<int>> dis1(n + 1);

	for (int i = 1; i <= n; i ++) {
		cout << "? " << root << ' ' << i << endl;
		int x;
		cin >> x;
		if (!vis[i]) {
			dis1[x].push_back(i);
		}
	} 

	for (int i = 0; i < n; i ++) {
		if (dis1[i].size() == 1 && dis1[i + 1].size() >= 1) {
			ans.push_back({dis1[i][0], dis1[i + 1][0]});
		}
	}

	cout << "! " << endl;
	for (auto [u, v] : ans) {
		cout << u << ' ' << v << endl;
	}

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}