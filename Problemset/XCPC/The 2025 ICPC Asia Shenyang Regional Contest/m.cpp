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

double f(vector<array<int, 2>> a, int id){
	vector<double> b(8), c(8), d(8);
	auto get = [&](int x, int y)->double{
		if(x > y){
			return (double)a[x][1] / (a[x][1] + a[y][0]);
		}else{
			return (double)a[x][0] / (a[x][0] + a[y][1]);
		}
	};
	for(int i = 0; i < 8; i ++){
		b[i] = get(i, i ^ 1);
	}
	auto get2 = [&](int st, int ed, int sst, int eed, vector<double> u, vector<double> &v)->void{
		for(int i = st; i <= ed; i ++){
			for(int j = sst; j <= eed; j ++){
				v[i] += u[i] * u[j] * get(i, j);
			}
		}
	};
	get2(0, 1, 2, 3, b, c);
	get2(2, 3, 0, 1, b, c);
	get2(4, 5, 6, 7, b, c);
	get2(6, 7, 4, 5, b, c);
	
	get2(0, 3, 4, 7, c, d);
	get2(4, 7, 0, 3, c, d);
	return d[id];
}

void solve() {
	vector<array<int, 2>> a(8);
	for(auto &[x, y] : a){
		cin >> x >> y;
	}
	vector<array<int, 2>> path;
	vector<int> vis(8);
	int id = 0;
	double ans = 0;
	auto dfs = [&](auto &&self, int cnt)->void{
		if(cnt == 8){
			ans = max(ans, f(path, id));
			return;
		}
		for(int i = 0; i < 8; i ++) if(!vis[i]){
			if(i == 0){
				id = cnt;
			}
			vis[i] = true;
			path.push_back(a[i]);
			self(self, cnt + 1);
			path.pop_back();
			vis[i] = false;
		}
	};
	dfs(dfs, 0);
	printf("%.12lf\n", ans);
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}