#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), cnt(n + 1);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	// sort(cnt.begin(), cnt.end(), greater<int>{});
	int mx = *max_element(cnt.begin(), cnt.end());
	cout << n / mx << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}