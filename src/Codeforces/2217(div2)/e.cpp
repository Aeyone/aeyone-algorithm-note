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
	vector<int> p(n), d(n);
	for (auto &e : p) {
		cin >> e;
	}
	for (auto &e : d) {
		cin >> e;
	}
	vector<int> g(n), q(n); // g[i] = ∑[p[i] < p[j]]，其中：i < j
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			g[i] += (p[j] > p[i]);
		}
	}
	for (int i = 1; i <= n; i ++) { // 按照1~n的顺序贪心放
		int x = -1;
		for (int j = 0; j < n; j ++) {
			if (q[j] != 0) {
				continue;
			}
			if (g[j] == d[j]) { // 之后要放的数字一定都会比i更大，所以只有g[j]==d[j]才能放
				x = j;			// 一定是第一个满足条件的位置放
				q[j] = i;
				break;
			}
		}
		if (x == -1) {
			cout << "-1" << '\n';
			return;
		}
		for (int j = 0; j < x; j ++) { 	// 放完之后，之后所有数字大于i
			g[j] -= (p[x] > p[j]);		// 消除该位置对左边位置的影响，右边位置没有影响
		}
	}
	for (auto e : q) {
		cout << e << ' ';
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