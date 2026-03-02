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
*	容易得到n^2转移：dp[i] = (1<=j<i)Min(dp[j] + (h[i]-h[j])^2 + C)
*
*	假设从j转移到i，展开得到：dp[i] = dp[j] + h[i]^2 + h[j]^2 - 2*h[i]*h[j] + C
*
*	那么对于所有可能的(1<=j<i)j，为同一个 i, 所以(h[i]^2 + C)视为常量P
*	观察到(dp[j] + h[j]^2)这两项只和j相关，设为f[j]
*	那么只剩下(-2*h[i]*h[j])这项了，对于所有j，(-2*h[i])为一个固定的斜率，设为k
*
*	整理一下，dp[i] = k * h[j] + f[j] + P
*
*	假设现在有j1 < j2，如果选择j1不比j2坏，可以得到：
*		k * h[j1] + f[j1] <= k * h[j2] + f[j2]
*	->	k * (h[j1] - h[j2]) <= f[j2] - f[j1]
*	->  k >= (f[j2] - f[j1]) / (h[j1] - h[j2])   // j1 < j2，h递增，那么h[j1] - h[j2]一定为负，要变号
*	->  -2 * h[i] >= (f[j2] - f[j1]) / (h[j1] - h[j2])
*	->  2 * h[i]  <= (f[j1] - f[j2]) / (h[j1] - h[j2])
*	
*	因此(f[j1] - f[j2]) / (h[j1] - h[j2]) 可以视为j1和j2两点的斜率
*
*	设slope(i, j)为(i, f[i])和(j, f[j])的斜率
*	可以得到结论：设j1 < j2，如果选择j1不比j2坏，需要满足2 * h[i]  <= slope(j1, j2)
*	
*	那么对于三个点，j1 < j2 < j3，要使得j2为最优决策点
*	  1)选择j2相比j1更优，则：2 * h[i] >= slope(j1, j2)
*	  2)选择j2相比j3更优，则：2 * h[i] <= slope(j2, j3)
*	可以得到：slope(j1, j2) < slope(j2, j3)
*
*	假设slope(j1, j2) >= slope(j2, j3)
*	那么j2一定不是最优决策点，一定可以把j2删掉，也就是要维护斜率单调上升的性质，才能保证所有点为最优决策点
*	这个时候得到的图形就变成了一个凸壳，那么对于每个i，只要找到第一个满足2 * h[i] >= slope(j1, j2)的位置即可，此时j2为最优点
*	由于h是单调递增的，那么可以直接用单调队列维护以上内容。
*/

void solve() {
	int n;
	i64 c;
	cin >> n >> c;
	vector<i64> h(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> h[i];
	}
	vector<i64> dp(n + 1);

	auto slope = [&](int i, int j)->double{
		return double(h[i] * h[i] - h[j] * h[j] + dp[i] - dp[j]) / (h[i] - h[j]);
	};

	deque<int> q; // 维护满足单调性质的所有下标
	q.push_back(1);
	dp[1] = 0;
	for (int i = 2; i <= n; i ++) {
		while (q.size() >= 2 && slope(*q.begin(), *(++q.begin())) <= 2 * h[i]) {
			q.pop_front();
		}
		int j = q.front(); // 找到第一个斜率大于2 * h[i]的位置
		dp[i] = dp[j] + (h[j] - h[i]) * (h[j] - h[i]) + c;
		while (q.size() >= 2 && slope(*(++q.rbegin()), *q.rbegin()) >= slope(*q.rbegin(), i)) {
			q.pop_back();
		}
		q.push_back(i); // 保持队列内的斜率保持单调递增后，插入当前下标
	}
	cout << dp[n] << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}