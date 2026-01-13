#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(1e6 + 10);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	i64 L = 1;	
	for(int i = 0; i < n; i ++) {
		cnt[a[i]] ++;
		if((__int128)L / gcd(L, a[i]) * a[i] > INFLL){
			cout << -1 << '\n';
			return;
		}
		L = L / gcd(L, a[i]) * a[i];
	}
	bool ok = false;
	for(int i = 0; i < n; i ++) {
		ok |= (a[i] == L);
	}
	int num = L;

	for(int i = 2; i <= L / i; i ++) {
		if(L % i == 0){
			num = i;
			break;
		}
	}
	if((__int128)L * num > INFLL) {
		cout << -1 << '\n';
		return;
	}
	if(ok) {
		L = L * num;
	}
	ok = true;
	for(int i = 2; i <= L / i; i ++) {
		if(L % i == 0) {
			ok &= (cnt[i] > 0);
			ok &= (L / i <= 1e6 && cnt[L / i] > 0);
		}
	}
	cout << (ok ? L : -1) << '\n';
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