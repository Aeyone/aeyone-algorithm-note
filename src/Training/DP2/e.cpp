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
	vector<vector<int>> dp(2, vector<int>(m + 1));
	for (int i = 0; i < n; i ++) {
        int w, v, c;
        cin >> w >> v >> c;
        dp[i & 1] = dp[i - 1 & 1];
        for (int j = 0; j < w; j ++) {
            deque<int> q;
            for (int k = j; k <= m; k += w) {
                if (q.size() && q.front() < k - c * w) {
                    q.pop_front();
                }
                if (q.size()) {
                    dp[i & 1][k] = max(dp[i - 1 & 1][k], dp[i - 1 & 1][q.front()] + (k - q.front()) / w * v);
                }
                while (q.size() && dp[i - 1 & 1][k] >= dp[i - 1 & 1][q.back()] + (k - q.back()) / w * v) {
                    q.pop_back();
                }
                
                q.push_back(k);
            }
        }
    }
	cout << dp[n - 1 & 1][m] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
    // cin >> _;
	while (_ --) {
		solve();
	}
}