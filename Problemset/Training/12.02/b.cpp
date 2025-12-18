#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
const int N = 5001;
int c[N][N];
int MOD;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	i64 ans = 1;
	for(int i = 0; i < n; i ++){
		ans = ans * c[sum][a[i]] % MOD;
		sum -= a[i];
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	cin >> MOD;
	for (int i = 0; i < N; i ++ ){
	    for (int j = 0; j <= i; j ++ ){//i中取上j个
	        if (!j){
	            c[i][j] = 1;
	        }else{
	            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	        }
	    }
	}
	while (_ --) {
		solve();
	}
}