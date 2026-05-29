#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 1e6;

void solve() {
	int n, d;
	cin >> n >> d;
	vector<vector<int>> g(N + 1);
	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}

	auto check = [&](int x)-> bool {
		deque<array<int, 2>> q1, q2;

		auto insert = [&](int i)-> void {
			for (auto y : g[i]){
				while (q1.size() && q1.back()[1] > y) {
					q1.pop_back();
				}
				q1.push_back({i, y});
				while (q2.size() && q2.back()[1] < y) {
					q2.pop_back();
				}
				q2.push_back({i, y});
			}
		};

		for (int i = 1; i <= x; i ++) insert(i);
		
		bool ok = false;
		for (int l = 1, r = x; r <= N; l ++, r ++) {
			while (q1.size() && q1[0][0] < l) q1.pop_front();
			while (q2.size() && q2[0][0] < l) q2.pop_front();
			ok |= (q1.size() && q2.size() && q2[0][1] - q1[0][1] >= d);
			if (r + 1 <= N) insert(r + 1);
		}
		return ok;
	};

	int l = 1, r = N, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid, r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << (ans == -1 ? -1 : max(1ll, ans - 1))<< '\n';
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