#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, k, p, m;
	cin >> n >> k >> p >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	p --;
	int x = a[p];
	multiset<int> st;
	for (int i = 0; i < k; i ++) {
		st.insert(a[i]);
	}
	int ans = 0, r = p - k + 1, cur = k;
	while (m > 0) {
		if (r <= 0) {
			r = n - k;
			m -= x;
			st.erase(st.find(x));
			a.push_back(x);
			st.insert(a[cur ++]);
			if (m < 0) {
				break;
			}
			ans ++;
			continue;
		} 
		auto it = st.begin();
		m -= *it;
		a.push_back(*it);
		st.insert(a[cur ++]);
		st.erase(it);
		r --;
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}