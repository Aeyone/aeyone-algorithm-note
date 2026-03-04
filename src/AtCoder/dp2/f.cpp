#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 1e9 + 7;

/*
*	队列中维护所有当前连续1长度为0~k-1的情况数量
*	上一个状态的所有情况，都可以转移到当前状态连续1长度为0的情况上
*	上一个0~k-1的状态，转移到当前1~k上面，需要把长度为k的情况数去掉
*/

void solve() {
	int n, k;
	cin >> n >> k;

	queue<i64> q;
	q.push(1);
	q.push(0);
	i64 tot = 1;
	for (int i = 1; i <= n - 2; i ++) {
		q.push(tot); 
		tot = 2 * tot % MOD;
		if (q.size() > k) {
			tot = (tot + MOD - q.front()) % MOD;
			q.pop();
		}
	}
	tot = (tot + MOD - q.front()) % MOD;
	cout << tot << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}