/*
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//   A    C    之   \./  之    真    理  \`.
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
	int n, m, N = 0;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		N = max(N, a[i]);
	}
	sort(a.begin(), a.end(), greater<int>{});
	vector<int> p(N + 1);
	vector<vector<int>> b(n);
	for(int i = 0; i < n; i ++){
		for(int j = 1; j <= a[i] / j; j ++){
			if(a[i] % j == 0){
				b[i].push_back(j);
				if(a[i] / j != j){
					b[i].push_back(a[i] / j);
				}
			}
		}
	}
	int cnt = 0, ans = INF;
	for(int l = 0, r = 0; l < n; l ++){
		while(r < n && cnt < m){
			for(auto e : b[r]){
				p[e] ++;
				cnt += (e <= m && p[e] == 1);
			}
			r ++;
		}
		if(cnt == m){
			ans = min(ans, a[l] - a[r - 1]);
		}
		for(auto e : b[l]){
			p[e] --;
			cnt -= (e <= m && p[e] == 0);
		}
	}
	if(ans != INF){
		cout << ans << '\n';
	}else{
		cout << -1 << '\n';
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