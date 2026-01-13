#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		b[i] = a[i] - i;
	}
	if(a[1] != 1){
		cout << 1 << '\n';
		return;
	}
	i64 cur = 1;
	while(k --){
		cur += (--lower_bound(b.begin(), b.end(), cur)) - b.begin();
	}
	cout << cur << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}