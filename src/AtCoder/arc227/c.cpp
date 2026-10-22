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
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans;
	for (int i = 0; i < n; i ++) ans += s;
	s = " " + s;
	vector<int> ne(n + 1);
	for (int i = 2, j = 0; i <= n; i ++) { 
		while (j && s[i] != s[j + 1]) {     
			j = ne[j];                
		}
		if (s[i] == s[j + 1]) {
			j ++;
		}
		ne[i] = j;
	}

	int p = n - ne[n];

	if (n % p != 0) {
	    p = n;
	}

	int k = n / p;
	cout << k << '\n';	
	cout << n * n << '\n';
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	// cin >> t;
	while (t --) {
		solve();
	}
}