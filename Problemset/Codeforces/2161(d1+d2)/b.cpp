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
	int n;
	cin >> n;
	vector<string> g(n);
	int tot = 0;
	for(int i = 0; i < n; i ++){
		cin >> g[i];
		tot += count(g[i].begin(), g[i].end(), '#');
	}
	auto f = [&]()->bool{
		int cnt = (g[0][0] == '#');
		bool ok = false;
		for(int i = 1; i < 2 * n; i ++){
			for(int j = 0, k = i; j < n && k >= 0; j ++, k --){
				if(k >= n){
					continue;
				}
				cnt += (g[k][j] == '#');
			}
			ok |= (cnt == tot);
			for(int j = 0, k = i - 1; j < n && k >= 0; j ++, k --){
				if(k >= n){
					continue;
				}
				cnt -= (g[k][j] == '#');
			}
		}
		return ok;
	};
	bool ok = false;
	for(int i = 0; i < n - 1; i ++){
		for(int j = 0; j < n - 1; j ++){
			int cnt = 0;
			cnt += (g[i][j] == '#');
			cnt += (g[i][j + 1] == '#');
			cnt += (g[i + 1][j] == '#');
			cnt += (g[i + 1][j + 1] == '#');
			ok |= (cnt == tot);
		}
	}
	ok |= f();
	for(auto &e : g){
		reverse(e.begin(), e.end());
	}
	ok |= f();
	if(ok){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
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