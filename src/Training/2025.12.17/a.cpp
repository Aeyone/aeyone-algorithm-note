#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() { //双指针 贪心(假的*1800)
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int u = n;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && s[r] == s[l]) {
			r ++;
		}
		if(r - l == k) {
			continue;
		}else{
			u = r;
			if(r - l > k) {
				u -= k;
			}
			break;
		}
	}
	string ss = s.substr(0, u);
	reverse(ss.begin(), ss.end());
	s += ss;
	s = s.substr(u, n - u + ss.size());
	bool ok = true;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && s[r] == s[l]) {
			r ++;
		}
		ok &= (r - l == k);
	}
	if(ok) {
		cout << u << '\n';
	}else{
		cout << -1 << '\n';
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