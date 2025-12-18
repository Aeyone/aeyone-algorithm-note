#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	while (1){
		int n;
		cin >> n;
		if(!n){
			break;
		}
		int sum = 0;
		vector<int> a(n);
		for(int i = 0; i < n; i ++){
			cin >> a[i];
			sum += a[i];
		}
		int dp[10][30][30] = {};
		for(int i = 0; i < sum; i ++){
			dp[0][0][i] = 1;
		}
		for(int i = 1; i < a[0]; i ++){
			for(int j = 0; j < sum; j ++){
				for(int k = 0; k < j; k ++){//必须满足k < j
					dp[0][i][j] += dp[0][i - 1][k];
				}
			}
		}
		for(int c = 1; c < n; c ++){
			for(int i = 0; i < sum; i ++){
				for(int j = 0; j < i; j ++){
					dp[c][0][i] += dp[c - 1][0][j];
				}
			}
		}
		for(int c = 1; c < n; c ++){
			for(int i = 1; i < a[c]; i ++){
				for(int j = 0; j < sum; j ++){
					for(int k = 0; k < sum; k ++){
						for(int la = 0; la < sum; la ++){
							if(j < k && j < la){
								dp[c][i][j] += dp[c][i - 1][k] + dp[c - 1][i][la];
							}
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < sum; i ++){
			ans += dp[n - 1][a[n - 1]][i];
		}
		cout << ans << '\n';
	}
}