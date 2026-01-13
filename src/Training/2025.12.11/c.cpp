#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	while(a.back() == 1) {
		a.pop_back();
	}
	reverse(a.begin(), a.end());
	if(*min_element(a.begin(), a.end()) == 1) {
		cout << -1 << '\n';
		return;
	}
	n = a.size();
	if(!n) {
		cout << 0 << '\n';
		return;
	}
	int ans = 0;
	for(int i = 1; i < n; i ++){
		while(1ll * a[i] * a[i] <= a[i - 1]) {
			a[i] = a[i] * a[i];
			ans ++;
		}
	}
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