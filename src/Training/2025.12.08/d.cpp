#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<i64> a;
	i64 ans = 0;
	for(int l = 0, r = 0; l < n; r ++, l = r){
		while(r < n && s[r] != '0'){
			r ++;
		}
		ans += 1ll * (r - l + 1) * (r - l) / 2;
		a.push_back(r - l + 1);
	}
	if(s.back() != '1'){
		a.push_back(1);
	}
	int m = a.size();
	for(int i = 0; i < m - 2; i ++){
		ans += a[i] * a[i + 2];
		a[i + 2] += a[i];
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}