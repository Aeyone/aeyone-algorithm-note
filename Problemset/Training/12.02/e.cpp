#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	vector<double> a(n);
	multiset<pair<double, i64>> st;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		st.insert({a[i], 1});
	}
	while(k > 0){
		auto it = --st.end();
		auto [e, c] = *it;
		st.erase(it);
		if(k - c >= 0){
			k -= c;
			st.insert({e / 2, c * 2});
		}else{
			st.insert({e / 2, 2ll * k});
			st.insert({e, c - k});
			k = 0;
		}
	}
	while(x > 0){
		auto [_, c] = *--st.end();
		x -= c;
		if(x > 0){
			st.erase(--st.end());
		}
	}
	auto [ans, _] = *--st.end();
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(12);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}