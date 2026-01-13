#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//位运算+贪心
	int n;
	cin >> n;
	vector<i64> a(n);
	int bit[30] = {};
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		for(int j = 0; a[i] >> j > 0; j ++){
			bit[j] += (a[i] >> j & 1);
		}
	}
	i64 ans = 0;
	for(int i = 0; i < n; i ++){
		i64 mask = 0;
		for(int j = 20; j >= 0; j --){
			if(bit[j]){
				mask += (1 << j);
				bit[j] --;
			}
		}
		ans += mask * mask;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}