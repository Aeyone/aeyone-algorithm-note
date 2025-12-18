#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	i64 n, k;
	cin >> n >> k;
	vector<array<i64, 3>> alls(n);
	multiset<pair<i64, i64>> st;
	i64 sum = 0, T = 0;
	for(auto &[a, b, c] : alls) {
		cin >> a >> b >> c;
		T = max(T, a);
		while(st.size() && st.begin()->first <= T){
			sum -= st.begin()->second;
			st.erase(st.begin());
		}
		while(sum + c > k){
			T = st.begin()->first;
			sum -= st.begin()->second;
			st.erase(st.begin());
		}
		cout << T << '\n';
		st.insert({T + b, c});
		sum += c;
	}
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