/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理   \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.
*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<i64>> h(n, vector<i64>(m));
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> h[i][j];
		}
	}
	i64 cost = 0;
	for(int i = 0; i < n - 1; i ++){
		i64 suf = 0;
		for(int j = m - 1; j >= 0; j --){
			if(h[i][j] > 0){
				h[i + 1][j] += max(0ll, h[i][j] + suf);
				suf = min(0ll, suf + h[i][j]);
				h[i][j] = 0;
			}else{
				suf += h[i][j];
			}
		}
		cost += abs(suf);
	}
	i64 suf = 0;
	for(int i = m - 1; i >= 0; i --){
		if(h[n - 1][i] > 0){
			cost += max(0ll, h[n - 1][i] + suf);
		}
		suf = min(0ll, suf + h[n - 1][i]);
	}
	cost += abs(suf);
	cout << cost << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}