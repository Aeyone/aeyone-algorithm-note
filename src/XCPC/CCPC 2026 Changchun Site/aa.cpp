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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)), dp(n, vector<int>(m));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int j = 0; j < m-1; j ++) {
		int cur = n-1;
		for (int i = n - 1; i >= 0; i --) {
			int x = (a[i][j] - dp[i][j]);
			ans += x;
			while(a[i][j]&&cur>=i){
				int mi = min(a[i][j],a[cur][j+1]-dp[cur][j+1]);
				a[i][j]-=mi;
				dp[cur][j+1]+=mi;
				if(dp[cur][j+1]==a[cur][j+1])cur--;
			}

		}
	}
	for(int i = 0 ;i<n;i++){
		ans+=a[i][m-1]-dp[i][m-1];
	}
	cout<<ans<<"\n";
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





// 89

