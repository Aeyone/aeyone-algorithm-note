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
	vector<int> cnt(n + 1, INF);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		cnt[x] = 1;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 2; j <= n / j; j ++) {
			if (i % j == 0) {
				if (cnt[j] != -1 && cnt[i / j] != -1) {
					cnt[i] = min(cnt[i], cnt[j] + cnt[i / j]);
				}
			}
		}
		cout << (cnt[i] >= INF ? -1 : cnt[i]) << ' ';
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