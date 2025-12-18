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

vector<vector<string>> p(3);

void init(){
	vector<int> vis(5);
	string path;
	auto dfs = [&](auto &&self, int c, int siz)->void{
		if(c == siz){
			p[siz - 2].push_back(path);
		}
		for(int i = 1; i <= siz; i ++) if(!vis[i]){
			path += ('0' + i);
			vis[i] = true;
			self(self, c + 1, siz);
			vis[i] = false;
			path.pop_back();
		}
	};
	for(int i = 2; i <= 4; i ++){
		dfs(dfs, 0, i);
	}
}

void solve() {
	int i, j;
	string s;
	cin >> s;
	cin >> i >> j;
	i --, j --;
	int cnt = 0, n = s.size() - 2;
	for(int k = 0; k < s.size(); k ++){
		cnt += (p[n][i][k] == p[n][j][k]);
	}
	cout << cnt << "A" << s.size() - cnt << "B" << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	init();
	// for(int i = 0; i < 3; i ++){
	// 	for(auto e : p[i]){
	// 		cout << e << ' ';
	// 	}
	// 	cout << '\n';
	// }
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}