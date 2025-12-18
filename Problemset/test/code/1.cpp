#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	if(n == 1 && s[0] != 'W') {
		cout << "NO" << '\n';
		return;
	}
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		a[i] = (s[i] == 'W');
	}
	// for(auto e : a) {
	// 	cout << e << ' ';
	// }
	// cout << '\n';
	bool ok = true;
	for(int l = 0, r = 0; l < n; l = r) {
		set<char> st;
		while(r < n && a[r] == a[l]) {
			st.insert(s[r]);
			r ++;
		}
		// cout << "l, r = " << l << ' ' << r << '\n';
		if(s[l] == 'W'){
			continue;
		}
		ok &= (st.size() == 2);
	}
	if(ok) {
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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