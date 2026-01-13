#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {//双指针 细节要考虑清楚
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i][0];
		a[i][1] = i;
	}
	sort(a.begin(), a.end());
	vector<int> ans(n);
	for(int l = 0, r = n - 1, i = 0; i < n; i ++) {
		while(i < n && a[l][0] - (n - 1 - r) == 0) {
			ans[a[l ++][1]] = -(n - i);
			i ++;
		}
		if(i < n) {
			if(a[l][0] - (n - 1 - r) < 0 || n - l - a[r][0] != 0) {
				cout << "NO" << '\n';
				return;
			}
			ans[a[r --][1]] = n - i;
		}
	}
	cout << "YES" << '\n';
	for(int j = 0; j < n; j ++) {
		cout << ans[j] << ' ';
	}
	cout << '\n';
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