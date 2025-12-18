#include <bits/stdc++.h>
using namespace std;

using i128 = __int128;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;

i128 qmi(i128 a, i128 b){
	i128 res = 1;
	while(b){
		if(b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res % mod;
}
void solve() {
	long long n;
	cin >> n;
	string s;
	cin >> s;
	i128 len = (i128)n * s.size();
	int ans = (qmi(2, len) - 1) % mod;
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}