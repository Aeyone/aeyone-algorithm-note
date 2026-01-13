#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {//有趣贪心
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	multiset<int> st;
	for(int i = 0; i < n; i ++) {
		cin >> a[i][0] >> a[i][1];
		st.insert(a[i][1]);
	}
	sort(a.begin(), a.end(), greater<array<int, 2>>{});
	int pre = -INFLL, ans = INFLL;
	for(int i = 0; i < n; i ++) {
		st.erase(st.find(a[i][1]));
		auto it = st.lower_bound(a[i][0]);
		if(it != st.end()) {
			ans = min(ans, abs(max(pre, *it) - a[i][0]));
		}
		if(it != st.begin()) {
			ans = min(ans, abs(a[i][0] - max(pre, *(--it))));
		}
		ans = min(ans, abs(a[i][0] - pre));
		pre = max(pre, a[i][1]);
	}
	cout << ans << '\n';
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