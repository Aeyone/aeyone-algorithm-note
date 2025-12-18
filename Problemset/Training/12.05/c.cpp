#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;
const int N = 2e6 + 10;
int s[N], id[N];

void init(){
	int cur = 1;
	for(int i = 1; cur <= 1e6; i ++){
		for(int j = 0; j < i; j ++){
			id[cur ++] = i;
		}
	}
	for(int i = 1; i <= 1e6; i ++){
		s[i] = s[i - 1] + 1ll * i * i;
	}
}

void solve() {
	int n;
	cin >> n;
	int x = id[n], d = n - (x * (x + 1) / 2 - x + 1);
	cerr << "x = " << x << " d = " << d << '\n';
	int ans = 0;
	for(int i = x; i >= 1; i --){
		int u = (i * (i + 1) / 2 - i + 1);
		int l = max(u, u + d - (x - i)), r = min(u + i - 1, u + d);
		cerr << "u = " << u << ' ';
		cerr << "l = " << l << " r = " << r << '\n';
		ans += s[r] - s[l - 1];
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init();
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}