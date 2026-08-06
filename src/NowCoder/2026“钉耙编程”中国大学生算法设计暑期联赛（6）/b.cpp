#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

#ifdef LOCAL 
    int test = 1;
#else
    int test = 1;
#endif

const int MOD = 998244353;

string to_string(i64 num, int base){
	if(num == 0){
		return "0";
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 2, vector<int>(m + 2));

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> g[i][j];
        }
    }

    int cost[1 << 6] {};
    int c2[6] = {0, 0, 7, 13, 14};
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

    for (int mask = 1; mask < 1 << 6; mask ++) {
        int cnt = __builtin_popcount(mask);
        int c1 = cnt * (6 + (6 - cnt + 1)) / 2;
        int need = 0;
        for (int i = 0; i < 6; i += 2) {
            need += ((mask >> i & 1) && (mask >> (i ^ 1) & 1));
        }
        if (need == cnt / 2 && cnt >= 2 && cnt <= 4) {
            cost[mask] = c2[cnt];
        } else {
            cost[mask] = c1;
        }
    }
    
    i64 ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (!g[i][j]) continue;
            vector<int> v = {0, 1, g[i][j] - 1, g[i][j]};
            for (int k = 0; k < 4; k ++) {
                int x = i + dx[k], y = j + dy[k];
                v.push_back(g[x][y]);
            }
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            int N = v.size();

            for (int k = 1; k < N; k ++) {
                if (v[k] > g[i][j]) continue;
                int mask = 0;
                if (v[k] == 1) mask |= (1 << 4);
                if (v[k] == g[i][j]) mask |= (1 << 5);

                for (int p = 0; p < 4; p ++) {
                    int x = i + dx[p], y = j + dy[p];
                    if (g[x][y] < v[k]) {
                        mask |= (1 << p);
                    }
                }
                ans += (1ll * cost[mask] * (v[k] - v[k - 1]));
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    if (test) cin >> t;
    while (t --) {
        solve();
    }
}