#include <bits/stdc++.h>
using namespace std;

// using i64 = long long;
#define int long long
const int inf = 1e17;
vector<pair<int, int>> v(10);

int g[16][16], cost[16];
int dp[20][1 << 16][20];
int a1, a2, a3, a4;

void init () {
    cin >> a1 >> a2 >> a3 >> a4;

    v[1] = { 1,a1 };
    v[2] = { 2,a1 };
    v[3] = { 4,a1 };
    v[4] = { 8,a1 };

    v[5] = { 3,a2 };
    v[6] = { 12,a2 };

    v[7] = { 5,a3 };
    v[8] = { 10,a3 };

    v[9] = { 15,a4 };

    for (int i = 0;i < 16;i++) {
        for (int j = 0;j < 16;j++) {
            if (i != j)
            	g[i][j] = inf;
        }
    }

    for (int i = 0;i < 16;i++) {
        g[i][i] = min ({ a1,a2,a3,a4 }) * 2;
    }

    for (int i = 0;i < 16;i++) {
        for (int j = 1;j < 10;j++)
        	g[i][i ^ v[j].first] = v[j].second;
    }

    for (int k = 0;k < 16; k++) {
        for (int i = 0;i < 16; i++) {
            for (int j = 0;j < 16; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for(int i = 0; i < 16; i ++)
    	cost[i] = g[0][i];

    int n = 16;
    vector<int> a(n);
    for(int i = 0; i < n; i ++)
    	a[i] = i;
    
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int mask = 0; mask < 1 << n; mask ++){
			if(__builtin_popcountll(mask) != i)
				continue;
			for(int j = 0; j < n; j ++) if(mask >> j & 1){
				for(int k = 0; k < 16; k ++){
					int cur = a[j] ^ k;
					int op = 15 ^ cur;
					dp[i][mask][k ^ op] = min(dp[i][mask][k ^ op], dp[i - 1][mask - (1 << j)][k] + cost[op]);
				}
			}
		}
	}
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int mask = 0;
	for(int i = 0; i < n; i ++){
		string s1, s2;
		cin >> s1 >> s2;
		s1 += s2;
		for(int j = 0; j < 4; j ++)
			if(s1[j] == '1')
				a[i] += (1 << j);
		mask += (1 << a[i]);
	}
	int ans = inf;
	for(int i = 0; i < 16; i ++)
		ans = min(ans, dp[n][mask][i]);

	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	init();
	while (_ --)
		solve();
}