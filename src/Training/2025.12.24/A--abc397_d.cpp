#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

i128 qmi(i128 a, i128 b){
	i128 res = 1;
	for( ;b ; b >>= 1, a = a * a) if(b & 1){
		res = a * res;
	}
	return res;
}

void solve() {
	i64 n;
	cin >> n;
	auto check = [&](i64 x)->i64{
		i64 l = 1, r = 1e9, ans = -1;
		while(l <= r) {
			i64 mid = (l + r) / 2;
			if(qmi(x + mid, 3) - qmi(mid, 3) >= n) {
				ans = mid, r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		if(ans != -1 && qmi(x + ans, 3) - qmi(ans, 3) == n){
			return ans;
		}else{
			return -1;
		}
	};
	for(int x = 1; x <= 1e8; x ++) {
		if(n % x == 0){
			i64 ans = check(x);
			if(ans != -1) {
				cout << x + ans << ' ' << ans << '\n';
				return;
			}
		}
	}
	cout << -1 << '\n';
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