#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, k;
	cin >> n >> k;
	vector<array<int, 2>> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i][0] >> a[i][1];
	}
	sort(a.begin(), a.end(), greater<array<int, 2>>{});
	i64 sum = 0;
	for(int i = 0; i < n; i ++){
		sum += a[i][1];
		if(sum > k){
			cout << a[i][0] + 1 << '\n';
			return;
		}
	}
	cout << 1 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}