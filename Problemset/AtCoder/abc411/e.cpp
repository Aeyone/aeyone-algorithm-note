#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 6>> a(n);
	set<int> st;
	vector<int> r1(n, 0), r2(n, 0);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < 6; j ++){
			cin >> a[i][j];
			st.insert(a[i][j]);
		}
		sort(a[i].begin(), a[i].end());
	}
	for(auto e : st){
		for(int i = 0; i < n; i ++){
			if(r1[i] >= 6 || e <= a[i][r1[i]])
				continue;
			while(r1[i] < 6 && e > a[i][r1[i]])
				r1[i] ++;
		}
		for(int i = 0; i < n; i ++){
			if(r2[i] >= 6 || e < a[i][r2[i]])
				continue;
			while(r2[i] < 6 && e >= a[i][r2[i]])
				r2[i] ++;
		}
		i64 c1 = 1, c2 = 1;
		for(int i = 0; i < n; i ++){
			c1 = c1 * r1[i] % mod;
			c2 = c2 * r2[i] % mod;
		}
		cout << 
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}