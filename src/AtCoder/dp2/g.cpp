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
*	变相计数DP，设dp[i]为以第i个字符为开头的子序列数量
*	这里有一个关于字符串子序列中不重复计算的Trick。
*	对于所有a~z的字母，我们只考虑所有该字母第一次出现的位置
*	设这个字母的位置为i，当前离要找的目标字符串还差k个字典序
*	 1)如果dp[i]<k，说明所有当前所有以i位置字母开头的情况都不足k个，需要跳过找下一个字母，同时更新k
*	 2)如果dp[i]>=k，说明答案在以这个字母开头的范围内，把其加入答案即可，记得把k减1代表后面不接任何字母的情况
*/

void solve() {
	string s; 
	cin >> s;
	int n = s.size();
	i64 k;
	cin >> k;

	s = " " + s;
	vector<i128> dp(n + 1);
	vector ne(n + 2, vector<int>(26, -1));
	for (int i = n; i >= 1; i --) {
		dp[i] = 1;
		for (int j = 0; j < 26; j ++) if (ne[i][j] != -1) {
			dp[i] += dp[ne[i][j]];
			if (dp[i] > INFLL) {
				dp[i] = INFLL;
			}
		}
		ne[i - 1] = ne[i];
		ne[i - 1][s[i] - 'a'] = i;
	}
	i128 tot = 0;
	for (int i = 0; i < 26; i ++) if (ne[0][i] != -1) {
		tot += dp[ne[0][i]];
	}
	if (tot < k) {
		cout << "Eel" << '\n';
		return;
	}

	int cur = 0;
	string ans;
	while (k > 0) {
		for (int i = 0; i < 26; i ++) if (ne[cur][i] != -1) {
			if (dp[ne[cur][i]] < k) {
				k -= dp[ne[cur][i]];
			} else {
				k --;
				ans += char('a' + i);
				cur = ne[cur][i];
				break;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}