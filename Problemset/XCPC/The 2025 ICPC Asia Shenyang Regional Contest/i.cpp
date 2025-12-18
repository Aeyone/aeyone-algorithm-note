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
	vector<array<int, 3>> v(n);
	vector<vector<int>> vis(500, vector<int>(15));
	vector<int> cnt(500);
	for(auto &[a, b, c] : v){
		cin >> a >> b >> c;
		if(c < 240){
			if(!vis[a][b]){
				cout << b << '\n';
				cnt[a] ++;
			}else{
				cout << 0 << '\n';
			}
			vis[a][b] = true;
		}else{
			if(!vis[a][b] && cnt[a] < 3){
				cout << b << '\n';
				cnt[a] ++;
			}else{
				cout << 0 << '\n';
			}
			vis[a][b] = true;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}