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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), suf(n + 2);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	priority_queue<int> heap;
	for (int i = n; i >= 1; i --) {
		suf[i] = suf[i + 1] + a[i];
	}
	for (int i = 2; i <= n; i ++) {
		heap.push(suf[i]);
	}
	int cur = suf[1];
	for (int i = 1; i <= n; i ++) {
		cout << cur << ' ';
		if (heap.size()) {
			cur += heap.top();
			heap.pop();
		}
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