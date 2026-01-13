#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

/*
	比较有难度的背包DP
	由于Alice的最优操作一定是从小到大吃，那么我们就考虑Bob的最优操作
	把所有数字从小到大排序，然后压缩成一个新的数组，w[i]为第i大的数字的数量
	定义dp[i][v]为在前i个物品中，Bob吃掉v个的时候，Alice能吃的最少数量
						  +0
	1)Bob吃：  dp[i-1][v] ----> dp[i][v+a[i]+1]，条件为a[i]<=i-v-cnt
											^cnt为这个1的数量
					   	  +1
	2)Bob不吃：dp[i-1][v] ----> dp[i][v]
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(auto &e : a) {
		cin >> e;
		mp[e] ++;
	}
	vector<int> w = {0};
	for(auto [e, c] : mp) {
		w.push_back(c);
	}
	int m = w.size() - 1;
	vector<vector<int>> dp(m + 1, vector<int>(2 * n + 1, INF));
	dp[0][0] = 0;
	for(int i = 1; i <= m; i ++) {
		for(int v = 0; v <= 2 * n; v ++) {
			dp[i][v] = min(dp[i][v], dp[i - 1][v] + 1);
			if(v + w[i] + 1 <= 2 * n && w[i] <= i - v - 1) {
				dp[i][v + w[i] + 1] = min(dp[i][v + w[i] + 1], dp[i - 1][v]); 
			}
		}
	}
	cout << *min_element(dp[m].begin(), dp[m].end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}