#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
/*
	博弈：
	其实是思维题，考虑先手可以一直维持在y = x + k这条直线上，后手可以一直维持在y = x上
	找一个y = x上最大满足 2 * n * n <= d * d 的点(n, n)，然后判断最终的点(n, n + k)
	1、如果合法，先手一定获胜
	2、如果不合法，那么终点为(n, n)，后手一定获胜
*/
void solve() {
	i64 d, k;
	cin >> d >> k;

	i64 n = d / sqrt(2);
	n = n / k * k;
	if(n * n + (n + k) * (n + k) <= d * d){
		cout << "Ashish" << '\n';
	}else{
		cout << "Utkarsh" << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}